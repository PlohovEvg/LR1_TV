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

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
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


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(204, 12);
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
			this->N_Text->Location = System::Drawing::Point(226, 144);
			this->N_Text->Name = L"N_Text";
			this->N_Text->Size = System::Drawing::Size(100, 29);
			this->N_Text->TabIndex = 1;
			this->N_Text->Text = L"100";
			// 
			// p_Text
			// 
			this->p_Text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->p_Text->Location = System::Drawing::Point(226, 179);
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
			this->label1->Location = System::Drawing::Point(12, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"„исло экспериментов";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(188, 182);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"p=";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(344, 144);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(673, 115);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(85, 293);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 58);
			this->button1->TabIndex = 6;
			this->button1->Text = L"—“ј–“";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1058, 560);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int N = Convert::ToInt32(N_Text->Text);
		double p = Convert::ToDouble(p_Text->Text);
		double q = 1 - p;
		double u;		
		double p_left = 0.0, p_right = p, p_cur = p;
		int j = 0;
		bool flag;
		List l;
		Eta a;

		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();

		dataGridView1->Columns->Add("Column1", "Yi");

		dataGridView1->Rows->Add("ni");
		dataGridView1->Rows->Add("ni/N");
		dataGridView1->Rows->Add("P");
		
		srand(time(NULL));

		for (int i = 0; i < N; i++) 
		{
			flag = false;
			u = ((double) rand()) / RAND_MAX;			
			while (flag == false)
			{
				if ((u >= p_left) && (u < p_right))
				{
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

		char buffer1[10], buffer2[50];
		int i = 1;

		while (l.IsEmpty() == false)
		{						
			a = l.Get_last_Node();

			sprintf_s(buffer1, "%d", i);
			sprintf_s(buffer2, "%d", a.GetValue());

			dataGridView1->Columns->Add(gcnew String(buffer1), gcnew String(buffer2));
			dataGridView1->Rows[0]->Cells[i]->Value = a.GetNi();
			dataGridView1->Rows[1]->Cells[i]->Value = a.GetNi() / (double)N;
			dataGridView1->Rows[2]->Cells[i]->Value = a.GetP();

			i++;
			l.Delete_last_Node();
		}

	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
};
}
