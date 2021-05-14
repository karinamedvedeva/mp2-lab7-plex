#pragma once
#include "Plex.h"

namespace mp2lab7plexes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TChart* Plex;
		TChart* Plex1;
		TChart* Plex2;
		TPoint* CurrPoint;
		TPoint* CurrPoint1;
		TPoint* CurrPoint2;
		Point* pp = new Point;
		Point* newPoint = new Point;
		TChart* NewLine;
		TPoint* np;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
		  
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			BackColor = Color::LightBlue;
			gr = CreateGraphics();
			Plex = new TChart;
			Plex->SetVisible(false);
			Plex1 = new TChart;
			Plex1->SetVisible(false);
			Plex2 = new TChart;
			Plex2->SetVisible(false);
			CurrPoint = new TPoint;
			CurrPoint->SetX(0);
			CurrPoint->SetY(0);
			CurrPoint1 = new TPoint;
			CurrPoint1->SetX(0);
			CurrPoint1->SetY(0);
			CurrPoint2 = new TPoint;
			CurrPoint2->SetX(0);
			CurrPoint2->SetY(0);
		}
	public:
		Graphics^ gr;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::SeaGreen;
			this->button1->Location = System::Drawing::Point(21, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Построить дом";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Honeydew;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::IndianRed;
			this->button2->Location = System::Drawing::Point(144, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Сломать дом";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::SeaGreen;
			this->button3->Location = System::Drawing::Point(245, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 29);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Построить забор";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Honeydew;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::IndianRed;
			this->button4->Location = System::Drawing::Point(370, 10);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 29);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Сломать забор";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::Color::SeaGreen;
			this->button5->Location = System::Drawing::Point(486, 10);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(124, 29);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Посадить дерево";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Honeydew;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::Color::IndianRed;
			this->button6->Location = System::Drawing::Point(616, 10);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 29);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Срубить дерево";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(746, 476);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::SaddleBrown;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		TPoint* A = new TPoint(200, 150);
		TPoint* B = new TPoint(300, 250);
		TPoint* C = new TPoint(100, 250);
		TPoint* D = new TPoint(100, 400);
		TPoint* E = new TPoint(300, 400);
		TChart* CA = new TChart;
		TChart* AB = new TChart;
		TChart* BE = new TChart;
		TChart* ED = new TChart;
		TChart* DC = new TChart;
		TChart* CB = new TChart;

		CA->SetFirst(C);
		CA->SetLast(A);
		AB->SetFirst(CA);
		AB->SetLast(B);
		BE->SetFirst(AB);
		BE->SetLast(E);
		ED->SetFirst(BE);
		ED->SetLast(D);
		DC->SetFirst(ED);
		DC->SetLast(C);

		Plex->SetFirst(DC);
		Plex->SetLast(B);
	    Plex->Show(gr);
		Plex->SetVisible(true);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Plex->IsVisible())
		{
			Plex->Hide(gr);
			Plex->SetVisible(false);
		}
	}
	
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			   TPoint* O = new TPoint(25, 300);
			   TPoint* P = new TPoint(700, 300);
			   TPoint* R = new TPoint(700,401);
			   TPoint* S = new TPoint(25, 401);
			   TChart* OP = new TChart;
			   TChart* PR = new TChart;
			   TChart* RS = new TChart;

			   OP->SetFirst(O);
			   OP->SetLast(P);
			   PR->SetFirst(OP);
			   PR->SetLast(R);
			   RS->SetFirst(PR);
			   RS->SetLast(S);

			   Plex1->SetFirst(RS);
			   Plex1->SetLast(O);
			   Plex1->Show(gr);
			   Plex1->SetVisible(true);
	}

    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Plex1->IsVisible())
		{
			Plex1->Hide(gr);
			Plex1->SetVisible(false);
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (Plex->IsVisible())
		{
			*pp = PointToClient(Control::MousePosition);
			CurrPoint = Plex->SetPoint(gr, pp->X, pp->Y);
			CurrPoint1 = Plex1->SetPoint(gr, pp->X, pp->Y);
			CurrPoint2 = Plex2->SetPoint(gr, pp->X, pp->Y);
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (Plex->IsVisible() && CurrPoint->GetX() > 0 && CurrPoint->GetY() > 0 && e->X != CurrPoint->GetX() && e->Y != CurrPoint->GetY())
		{
			*newPoint = PointToClient(Control::MousePosition);

			np = new TPoint(newPoint->X, newPoint->Y);
			NewLine = new TChart;

			NewLine->SetFirst(np);
			NewLine->SetLast(CurrPoint);

			Plex->AddLine(gr, CurrPoint, NewLine);
			Plex->Show(gr);

			Plex1->AddLine(gr, CurrPoint1, NewLine);
			Plex1->Show(gr);

			Plex2->AddLine(gr, CurrPoint2, NewLine);
			Plex2->Show(gr);
		}
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	TPoint* A = new TPoint(490, 210);
	TPoint* Z = new TPoint(510, 210);
	TPoint* B = new TPoint(445, 210);
	TChart* AB = new TChart;
	AB->SetFirst(A);
	AB->SetLast(B);
	TPoint* C = new TPoint(500, 90);
	TChart* BC = new TChart;
	BC->SetFirst(AB);
	BC->SetLast(C);
	TPoint* D = new TPoint(555, 210);
	TChart* CD = new TChart;
	CD->SetFirst(BC);
	CD->SetLast(D);
	TChart* DZ = new TChart;
	DZ->SetFirst(CD);
	DZ->SetLast(Z);
	TPoint* F = new TPoint(615, 400);
	TChart* ZF = new TChart;
	ZF->SetFirst(DZ);
	ZF->SetLast(F);
	TPoint* E = new TPoint(385, 400);
	TChart* FE = new TChart;
	FE->SetFirst(ZF);
	FE->SetLast(E);
	

	Plex2->SetFirst(FE);
	Plex2->SetLast(A);
	Plex2->Show(gr);
	Plex2->SetVisible(true);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Plex2->IsVisible())
	{
		Plex2->Hide(gr);
		Plex2->SetVisible(false);
	}
}
};
}
