#pragma once
#include <string>
#include <iostream>
#include "Stack.h"

using namespace System;
using namespace System::Drawing;

class TRoot
{
protected:
	bool Visible, Active;
public:
	TRoot()
	{
		Visible = true;
		Active = false;
	};

	bool IsVisible()
	{
		if (Visible == 1)
			return true;
	}

	bool IsActive()
	{
		if (Active == 1)
			return true;
	}

	void SetActive(bool _Active = true)
	{
		Active = _Active;
	};

	void SetVisible(bool _Visible = true)
	{
		Visible = _Visible;
	};
	
	virtual void Show(Graphics^ gr) = 0;
	virtual void Hide(Graphics^ gr) = 0;
};

class TPoint : public TRoot
{
protected:
	int x, y;
public:
	TPoint(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}

	void SetX(int _x)
	{
		x = _x;
	}

	void SetY(int _y)
	{
		y = _y;
	}

	virtual void Show(Graphics^ gr) 
	{
		gr->DrawEllipse(Pens::DarkGoldenrod, x - 2, y - 2, 4, 4);
		Visible = true;
	}

	virtual void Hide(Graphics^ gr)
	{
		gr->DrawEllipse(Pens::LightBlue, x - 2, y - 2, 4, 4);
		Visible = false;
	}
};

class TChart;
struct TLine
{
	TChart* pChart;
	TPoint* pFp, * pLp;
};

class TChart : public TRoot
{
protected:
	TRoot* pFirst, * pLast;
	Stack <TLine> St;
public:
	TChart(TRoot* _pFirst = NULL, TRoot* _pLast = NULL)
	{
		pFirst = _pFirst; 
		pLast = _pLast; 
		this->Visible = true;
	}

	int GetSize()
	{
		int size = 0;
		if (pFirst)
			size++;
		if (pLast)
			size--;
		return size;
	}

	TRoot* GetFirst()
	{
		return pFirst;
	}

	TRoot* GetLast()
	{
		return pLast;
	}

	void SetFirst(TRoot* p)
	{
		TPoint* pPoint = dynamic_cast<TPoint*>(p);
		TChart* pChart = dynamic_cast<TChart*>(p);
		if (pPoint || pChart)
			pFirst = p;
	}

	void SetLast(TRoot* l)
	{
		TPoint* pPoint = dynamic_cast<TPoint*>(l);
		TChart* pChart = dynamic_cast<TChart*>(l);
		if (pPoint || pChart)
			pLast = l;
	}
	
	 void Show(Graphics^ gr) 
	{
		TLine CurrLine;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		TRoot* pr;
		TPoint* pp;

		St.Clear();
		St.Push(CurrLine);

		while (!St.Empty())
		{
			CurrLine = St.Pop();
			while (CurrLine.pFp == NULL)
			{
				pr = CurrLine.pChart->GetFirst();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp != NULL)
				{
					CurrLine.pFp = pp;
					pp->Show(gr);
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (CurrLine.pLp == NULL)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp != NULL)
				{
					CurrLine.pLp = pp;
					pp->Show(gr);
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					St.Push(CurrLine);
				}
			}
			if (CurrLine.pFp != NULL && CurrLine.pLp != NULL)
			{
				gr->DrawLine(Pens::DarkGoldenrod, CurrLine.pFp->GetX(), CurrLine.pFp->GetY(), CurrLine.pLp->GetX(), CurrLine.pLp->GetY());
				pp = CurrLine.pLp;
				if (!St.Empty())
				{
					CurrLine = St.Pop();
					if (CurrLine.pFp == NULL)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
					St.Push(CurrLine);
				}
			}
		}
	}

    void Hide(Graphics^ gr)
	{
		TLine CurrLine;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		TRoot* pr;
		TPoint* pp;

		St.Clear();
		St.Push(CurrLine);

		while (!St.Empty())
		{
			CurrLine = St.Pop();
			while (CurrLine.pFp == NULL)
			{
				pr = CurrLine.pChart->GetFirst();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp != NULL)
				{
					CurrLine.pFp = pp;
					pp->Show(gr);
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (CurrLine.pLp == NULL)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp != NULL)
				{
					CurrLine.pLp = pp;
					pp->Show(gr);
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					St.Push(CurrLine);
				}
			}
			if (CurrLine.pFp != NULL && CurrLine.pLp != NULL)
			{
				gr->DrawLine(Pens::LightBlue, CurrLine.pFp->GetX(), CurrLine.pFp->GetY(), CurrLine.pLp->GetX(), CurrLine.pLp->GetY());
				pp = CurrLine.pLp;
				if (!St.Empty())
				{
					CurrLine = St.Pop();
					if (CurrLine.pFp == NULL)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
					St.Push(CurrLine);
				}
			}
		}

	}

	TPoint* SetPoint(Graphics^ gr, int _x, int _y)
	{
		TPoint* pC = new TPoint;
		TRoot* pr;
		TPoint* pp;
		TLine CurrLine;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
        St.Clear();
		St.Push(CurrLine);

		while (!St.Empty())
		{
			CurrLine = St.Pop();
			while (CurrLine.pFp == NULL)
			{
				pr = CurrLine.pChart->GetFirst();
				pp = dynamic_cast<TPoint*>(pr);
				if (pp != NULL)
				{
					CurrLine.pFp = pp;
					CurrLine.pFp->Show(gr);
					
					if (abs(_x - CurrLine.pFp->GetX()) < 3 && abs(_y - CurrLine.pFp->GetY()) < 3)
					{
						pC = CurrLine.pFp;
					}
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (CurrLine.pLp == NULL)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);

				if (pp != NULL)
				{
					CurrLine.pLp = pp;
					CurrLine.pLp->Show(gr);
					
					if (abs(_x - CurrLine.pLp->GetX()) < 3 && abs(_y - CurrLine.pLp->GetY()) <3)
					{
						pC = CurrLine.pLp;
					}
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					St.Push(CurrLine);
				}
			}
			if (CurrLine.pFp != NULL && CurrLine.pLp != NULL)
			{
				pp = CurrLine.pLp;

				if (!St.Empty())
				{
					CurrLine = St.Pop();
					if (CurrLine.pFp == NULL)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;

					St.Push(CurrLine);
				}
			}
		}
		pC->Show(gr);
		return pC;
	}

	void AddLine(Graphics^ gr, TPoint* pC, TChart* NewLine)
	{
		TLine CurrLine;
		TRoot* pr;
		TPoint* pp;
		CurrLine.pChart = this;
		CurrLine.pFp = CurrLine.pLp = NULL;
		St.Clear();
		St.Push(CurrLine);

		while (!St.Empty())
		{
			CurrLine = St.Pop();
			while (CurrLine.pFp == NULL)
			{
				pr = CurrLine.pChart->GetFirst();
				pp = dynamic_cast<TPoint*>(pr);

				if (pp != NULL)
				{
					CurrLine.pFp = pp;
					if (abs(pC->GetX() - CurrLine.pFp->GetX()) < 3 && abs(pC->GetY() - CurrLine.pFp->GetY()) < 3)
					{
						CurrLine.pChart->SetFirst(NewLine);
						return;
					}
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
				}
			}
			if (CurrLine.pLp == NULL)
			{
				pr = CurrLine.pChart->GetLast();
				pp = dynamic_cast<TPoint*>(pr);

				if (pp != NULL)
				{
					CurrLine.pLp = pp;
					if (abs(pC->GetX() - CurrLine.pLp->GetX()) < 3 && abs(pC->GetY() - CurrLine.pLp->GetY()) < 3)
					{
						CurrLine.pChart->SetLast(NewLine);
						return;
					}
				}
				else
				{
					St.Push(CurrLine);
					CurrLine.pChart = dynamic_cast<TChart*>(pr);
					CurrLine.pFp = NULL;
					St.Push(CurrLine);
				}
			}
			if (CurrLine.pFp != NULL && CurrLine.pLp != NULL)
			{
				pp = CurrLine.pLp;

				if (!St.Empty())
				{
					CurrLine = St.Pop();

					if (CurrLine.pFp == NULL)
						CurrLine.pFp = pp;
					else
						CurrLine.pLp = pp;
					St.Push(CurrLine);
				}
			}
		}
	}
};