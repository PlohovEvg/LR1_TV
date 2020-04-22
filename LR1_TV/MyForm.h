#pragma once
#include <stdlib.h>
#include <ctime>
#include "List.h"
#include <cmath>

namespace LR1_TV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;		
	using namespace ZedGraph;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::TextBox^  N_Text;
	private: System::Windows::Forms::TextBox^  p_Text;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;








	private: System::Windows::Forms::TextBox^  textBox1;	
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;

	private: System::ComponentModel::IContainer^  components;










	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->N_Text = (gcnew System::Windows::Forms::TextBox());
			this->p_Text = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(657, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(673, 102);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// N_Text
			// 
			this->N_Text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->N_Text->Location = System::Drawing::Point(872, 121);
			this->N_Text->Name = L"N_Text";
			this->N_Text->Size = System::Drawing::Size(100, 29);
			this->N_Text->TabIndex = 1;
			this->N_Text->Text = L"100";
			// 
			// p_Text
			// 
			this->p_Text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->p_Text->Location = System::Drawing::Point(872, 156);
			this->p_Text->Name = L"p_Text";
			this->p_Text->Size = System::Drawing::Size(100, 29);
			this->p_Text->TabIndex = 2;
			this->p_Text->Text = L"0,6";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(658, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Число экспериментов";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(834, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"p=";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(657, 200);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(673, 115);
			this->dataGridView1->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1008, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 58);
			this->button1->TabIndex = 6;
			this->button1->Text = L"СТАРТ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8
			});
			this->dataGridView2->Location = System::Drawing::Point(657, 387);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(673, 65);
			this->dataGridView2->TabIndex = 7;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"E";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"x~";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"|E-x~|";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"D";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"S^2";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"|D-S^2|";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Me^";
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"R^";
			this->Column8->Name = L"Column8";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(776, 321);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(381, 60);
			this->textBox1->TabIndex = 8;
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->IsShowPointValues = false;
			this->zedGraphControl1->Location = System::Drawing::Point(12, 3);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->PointValueFormat = L"G";
			this->zedGraphControl1->Size = System::Drawing::Size(639, 576);
			this->zedGraphControl1->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1342, 591);
			this->Controls->Add(this->zedGraphControl1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->p_Text);
			this->Controls->Add(this->N_Text);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		GraphPane^ panel1 = zedGraphControl1->GraphPane;

		panel1->CurveList->Clear();
		panel1->Title = "Графики F(x) и F^(x)";
		panel1->XAxis->Title = "X";
		panel1->YAxis->Title = "F(x)";

		PointPairList^ f_list = gcnew PointPairList();
		PointPairList^ f1_list = gcnew PointPairList();
		
		int N = Convert::ToInt32(N_Text->Text);
		double p = Convert::ToDouble(p_Text->Text);
		double q = 1 - p;
		double u;		
		double p_left = 0.0, p_right = p, p_cur = p;
		double MaxD = 0.0;
		double MaxSub = 0.0;
		double FR, FR1;
		double xMid = 0.0, S2 = 0.0, Me, R;
		double div;
		double xint, xfract;
		int xk, xkplus1;
		int j = 0;
		int k;		
		int m;
		bool flag;
		List l;
		Eta a;

		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		dataGridView2->Rows->Clear();		

		dataGridView1->Columns->Add("Column1", "Yi");

		dataGridView1->Rows->Add("ni");
		dataGridView1->Rows->Add("ni/N");
		dataGridView1->Rows->Add("P{(Eta=Yi)}");
		
		srand(time(NULL));

		for (int i = 0; i < N; i++) 
		{
			flag = false;
			u = ((double) rand()) / RAND_MAX;			
			while (flag == false)
			{
				if ((u >= p_left) && (u < p_right))
				{
					if (N % 2 == 0)
					{
						if (i == N*0.5 - 1)
						{
							xk = a.GetValue();
						}
						if (i == N*0.5)
						{
							xkplus1 = a.GetValue();
						}
					}
					else
					{
						if (i == (N - 1)*0.5)
						{
							xkplus1 = a.GetValue();
						}
					}
					a.SetP(p*pow(q, a.GetValue() - 1));										
					l.Add_new_Node(a);
					a.SetValue(1);
					p_left = 0.0;
					p_right = p;
					p_cur = p;
					flag = true;
				}
				else
				{	
					a.IncValue();
					p_cur = p_cur*q;
					p_left = p_right;
					p_right = p_left + p_cur;
				}
			}
		}

		k = l.Get_Number_of_Nodes();

		for (double x = -1.0; x <= 10.0; x = x + 0.05)
		{
			x = round(x * 100) / 100;

			xfract = modf(x, &xint);
			xfract = round(xfract * 100) / 100;

			m = 0;

			if (x < 1.0)
			{
				FR = 0.0;
			}
			else
			{
				if (xfract != 0.0)
				{
					FR = 1 - pow(q, xint);
				}
				else
				{
					FR = 1 - pow(q, x - 1.0);
				}			
			}

			for (int i = 1; i <= k; i++)
			{
				a = l.Get_Node(i);
				if ((double)a.GetValue() < x)
				{
					m = m + a.GetNi();
				}
			}

			FR1 = (double)m / N;

			if (abs(FR1 - FR) > MaxD)
			{
				MaxD = abs(FR1 - FR);
			}

			f_list->Add(x, FR);
			f1_list->Add(x, FR1);
		}

		LineItem^ Curve1 = panel1->AddCurve("F(x)", f_list, Color::Red, SymbolType::None);
		LineItem^ Curve2 = panel1->AddCurve("F^(x)", f1_list, Color::Black, SymbolType::None);

		panel1->XAxis->Min = -1.0;
		panel1->XAxis->Max = 10.0;

		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
		
		for (int i = 1; i <= k; i++)
		{
			a = l.Get_Node(i);
			xMid += a.GetValue()*a.GetNi();
		}

		xMid = (double)xMid / N;
		R = l.Get_Node(1).GetValue() - l.Get_Node(k).GetValue();

		if (N % 2 != 0)
		{			
			Me = (double)xkplus1;
		}
		else
		{
			
			Me = (double)(xk + xkplus1)*0.5;
		}
		
		for (int i = 1; i <= k; i++)
		{
			a = l.Get_Node(i);
			S2 += (a.GetValue() - xMid)*(a.GetValue() - xMid)*a.GetNi();
		}

		S2 = (double)S2 / N;

		char buffer1[10], buffer2[50];
		int i = 1;

		while (l.IsEmpty() == false)
		{						
			a = l.Get_last_Node();
			div = a.GetNi() / (double)N;

			sprintf_s(buffer1, "%d", i);
			sprintf_s(buffer2, "%d", a.GetValue());

			dataGridView1->Columns->Add(gcnew String(buffer1), gcnew String(buffer2));
			dataGridView1->Rows[0]->Cells[i]->Value = a.GetNi();
			dataGridView1->Rows[1]->Cells[i]->Value = div;
			dataGridView1->Rows[2]->Cells[i]->Value = a.GetP();

			if (abs(div - a.GetP()) > MaxSub)
			{
				MaxSub = abs(div - a.GetP());
			}

			i++;
			l.Delete_last_Node();
		}

		xMid = round(xMid * 1000) / 1000;
		S2 = round(S2 * 1000) / 1000;

		dataGridView2->Rows->Add();
		dataGridView2->Rows[0]->Cells[0]->Value = round((1 / p) * 1000) / 1000;
		dataGridView2->Rows[0]->Cells[1]->Value = xMid;
		dataGridView2->Rows[0]->Cells[2]->Value = abs((round((1 / p) * 1000) / 1000) - xMid);
		dataGridView2->Rows[0]->Cells[3]->Value = round((q / (p*p)) * 1000) / 1000;
		dataGridView2->Rows[0]->Cells[4]->Value = S2;
		dataGridView2->Rows[0]->Cells[5]->Value = abs((round((q / (p*p)) * 1000) / 1000) - S2);
		dataGridView2->Rows[0]->Cells[6]->Value = Me;
		dataGridView2->Rows[0]->Cells[7]->Value = R;

		string ref = "";
		ref += "max|(ni/N)-P{(Eta=Yi)}|=";
		sprintf_s(buffer1, "%.3lf", MaxSub);
		ref += buffer1;
		ref += "\r\n";
		ref += "D=max|F^(x)-F(x)|=";
		sprintf_s(buffer1, "%.3lf", MaxD);
		ref += buffer1;

		textBox1->Text = gcnew String(ref.c_str());
	}
};
}
