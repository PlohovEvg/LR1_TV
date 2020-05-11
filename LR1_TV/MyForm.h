#pragma once
#include <stdlib.h>
#include <ctime>
#include "List.h"
#include <cmath>
#include <Windows.h>

using namespace System::ComponentModel;

void Create_List(const int _N,List &_l,int &_xk,int &_xkplus1, const double _p, BackgroundWorker ^bw)  //Создание списка со значениями случайной величины
{
	double u;
	double q = 1 - _p;
	double p_left = 0.0, p_right = _p, p_cur = _p;
	bool flag;
	Eta b;

	srand(time(NULL));

	if (_N % 2 == 0)
	{
		for (int i = 0; i < _N*0.5 - 1; i++)   //Итерации от 0 до (_N/2) - 1
		{
			bw->ReportProgress((int)((double)i / _N * 100));
			flag = false;
			u = ((double)rand()) / RAND_MAX;
			while (flag == false)
			{
				if ((u >= p_left) && (u < p_right))
				{
					b.SetP(_p*pow(q, b.GetValue() - 1));
					_l.Add_new_Node(b);
					b.SetValue(1);
					p_left = 0.0;
					p_right = _p;
					p_cur = _p;
					flag = true;
				}
				else
				{
					b.IncValue();
					p_cur = p_cur*q;
					p_left = p_right;
					p_right = p_left + p_cur;
				}
			}
		}

		bw->ReportProgress((int)((double)(_N*0.5 - 1) / _N * 100));  //Итерация (_N/2) - 1
		flag = false;
		u = ((double)rand()) / RAND_MAX;
		while (flag == false)
		{
			if ((u >= p_left) && (u < p_right))
			{
				_xk = b.GetValue();
				b.SetP(_p*pow(q, b.GetValue() - 1));				
				_l.Add_new_Node(b);
				b.SetValue(1);
				p_left = 0.0;
				p_right = _p;
				p_cur = _p;
				flag = true;
			}
			else
			{
				b.IncValue();
				p_cur = p_cur*q;
				p_left = p_right;
				p_right = p_left + p_cur;
			}
		}

		bw->ReportProgress((int)((double)(_N*0.5) / _N * 100));  //Итерация _N/2
		flag = false;
		u = ((double)rand()) / RAND_MAX;
		while (flag == false)
		{
			if ((u >= p_left) && (u < p_right))
			{
				_xkplus1 = b.GetValue();
				b.SetP(_p*pow(q, b.GetValue() - 1));
				_l.Add_new_Node(b);
				b.SetValue(1);
				p_left = 0.0;
				p_right = _p;
				p_cur = _p;
				flag = true;
			}
			else
			{
				b.IncValue();
				p_cur = p_cur*q;
				p_left = p_right;
				p_right = p_left + p_cur;
			}
		}

		for (int i = (int)((_N*0.5) + 1); i < _N; i++)  //Итерации от (_N/2) + 1 до _N
		{
			bw->ReportProgress((int)((double)i / _N * 100));
			flag = false;
			u = ((double)rand()) / RAND_MAX;
			while (flag == false)
			{
				if ((u >= p_left) && (u < p_right))
				{
					b.SetP(_p*pow(q, b.GetValue() - 1));
					_l.Add_new_Node(b);
					b.SetValue(1);
					p_left = 0.0;
					p_right = _p;
					p_cur = _p;
					flag = true;
				}
				else
				{
					b.IncValue();
					p_cur = p_cur*q;
					p_left = p_right;
					p_right = p_left + p_cur;
				}
			}
		}
	}
	else
	{
		_xk = -1;

		for (int i = 0; i < (_N - 1)*0.5; i++)   //Итерации от 0 до (_N - 1)/2 
		{
			bw->ReportProgress((int)((double)i / _N * 100));
			flag = false;
			u = ((double)rand()) / RAND_MAX;
			while (flag == false)
			{
				if ((u >= p_left) && (u < p_right))
				{
					b.SetP(_p*pow(q, b.GetValue() - 1));
					_l.Add_new_Node(b);
					b.SetValue(1);
					p_left = 0.0;
					p_right = _p;
					p_cur = _p;
					flag = true;
				}
				else
				{
					b.IncValue();
					p_cur = p_cur*q;
					p_left = p_right;
					p_right = p_left + p_cur;
				}
			}
		}

		bw->ReportProgress((int)((double)((_N - 1)*0.5) / _N * 100)); //Итерация (_N-1)/2
		flag = false;
		u = ((double)rand()) / RAND_MAX;
		while (flag == false)
		{
			if ((u >= p_left) && (u < p_right))
			{
				_xkplus1 = b.GetValue();
				b.SetP(_p*pow(q, b.GetValue() - 1));
				_l.Add_new_Node(b);
				b.SetValue(1);
				p_left = 0.0;
				p_right = _p;
				p_cur = _p;
				flag = true;
			}
			else
			{
				b.IncValue();
				p_cur = p_cur*q;
				p_left = p_right;
				p_right = p_left + p_cur;
			}
		}

		for (int i = (int)(((_N - 1)*0.5) + 1); i < _N; i++)   //Итерации от ((_N - 1)/2) + 1 до _N
		{
			bw->ReportProgress((int)((double)i / _N * 100));
			flag = false;
			u = ((double)rand()) / RAND_MAX;
			while (flag == false)
			{
				if ((u >= p_left) && (u < p_right))
				{
					b.SetP(_p*pow(q, b.GetValue() - 1));
					_l.Add_new_Node(b);
					b.SetValue(1);
					p_left = 0.0;
					p_right = _p;
					p_cur = _p;
					flag = true;
				}
				else
				{
					b.IncValue();
					p_cur = p_cur*q;
					p_left = p_right;
					p_right = p_left + p_cur;
				}
			}
		}
	}
	
}


double fxi(double X, int r)
{
	if (X <= 0)
	{
		return 0.0;
	}
	else
	{
		return pow(2, -r*0.5)*pow(tgamma(r*0.5), -1)*pow(X, (r*0.5) - 1)*exp(-X*0.5);
	}
}

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
		int N;
		List *l;
		int K;		
		double p;
		int *xk, *xkplus1;
		int index;
		double *z;	
			 MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//				
			l = new List();			
			xk = new int();
			xkplus1 = new int();
			*xk = *xkplus1 = 0;						
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
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;	
	private: System::Windows::Forms::TextBox^  N_Text;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::TextBox^  p_Text;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  Alpha_Text;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::TextBox^  textBox2;	
	private: System::Windows::Forms::TextBox^  K_Text;
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
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;



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
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->K_Text = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Alpha_Text = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
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
			this->button1->Location = System::Drawing::Point(1168, 121);
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
			this->zedGraphControl1->Size = System::Drawing::Size(639, 648);
			this->zedGraphControl1->TabIndex = 9;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(680, 607);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(637, 44);
			this->progressBar1->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(986, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 24);
			this->label3->TabIndex = 12;
			this->label3->Text = L"k=";
			// 
			// K_Text
			// 
			this->K_Text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->K_Text->Location = System::Drawing::Point(1024, 121);
			this->K_Text->Name = L"K_Text";
			this->K_Text->Size = System::Drawing::Size(100, 29);
			this->K_Text->TabIndex = 11;
			this->K_Text->Text = L"5";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(986, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 24);
			this->label4->TabIndex = 14;
			this->label4->Text = L"α=";
			// 
			// Alpha_Text
			// 
			this->Alpha_Text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Alpha_Text->Location = System::Drawing::Point(1024, 156);
			this->Alpha_Text->Name = L"Alpha_Text";
			this->Alpha_Text->Size = System::Drawing::Size(100, 29);
			this->Alpha_Text->TabIndex = 13;
			this->Alpha_Text->Text = L"1";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column9,
					this->Column10
			});
			this->dataGridView3->Location = System::Drawing::Point(1353, 277);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(245, 397);
			this->dataGridView3->TabIndex = 15;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"i";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"qi";
			this->Column10->Name = L"Column10";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(776, 525);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(381, 60);
			this->textBox2->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(700, 479);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(198, 24);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Введите значения Zi";
			this->label5->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(909, 479);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(182, 29);
			this->textBox3->TabIndex = 18;
			this->textBox3->Visible = false;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(1118, 471);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(212, 48);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Использовать значения по умолчанию";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView4->Location = System::Drawing::Point(1353, 3);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(245, 268);
			this->dataGridView4->TabIndex = 20;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"i";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"zi";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1610, 675);
			this->Controls->Add(this->dataGridView4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Alpha_Text);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->K_Text);
			this->Controls->Add(this->progressBar1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
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

		N = Convert::ToInt32(N_Text->Text);		
		p = Convert::ToDouble(p_Text->Text);
		K = Convert::ToInt32(K_Text->Text);
		index = 1;
		z = new double[K + 1];
		z[0] = -INFINITY;
		z[K] = INFINITY;

		double Alpha = Convert::ToDouble(Alpha_Text->Text);
		double R0 = 0.0;
		double Integral = 0.0;		
		double MaxD = 0.0;
		double MaxSub = 0.0;
		double FR, FR1;
		double xMid = 0.0, S2 = 0.0, Me, R;
		double div;
		double xint, xfract;
		double *q;
		double FR0;
		int *nj;
		int k;		
		int m;			
		Eta a;
		
		q = new double[K];
		nj = new int[K];
		
		for (int i = 0; i < K; i++)
		{
			q[i] = 0.0;
			nj[i] = 0;
		}
				
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		dataGridView2->Rows->Clear();
		dataGridView3->Rows->Clear();
		dataGridView4->Rows->Clear();

		dataGridView1->Columns->Add("Column1", "Yi");

		dataGridView1->Rows->Add("ni");
		dataGridView1->Rows->Add("ni/N");
		dataGridView1->Rows->Add("P{(Eta=Yi)}");

		backgroundWorker1->RunWorkerAsync();
		while (backgroundWorker1->IsBusy)
		{
			Sleep(20);			
			Application::DoEvents();
		}
		
		k = l->Get_Number_of_Nodes();
	
		char buffer1[10], buffer2[50];
	
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
					FR = 1 - pow(1 - p, xint);
				}
				else
				{
					FR = 1 - pow(1 - p, x - 1.0);
				}			
			}

			for (int i = 1; i <= k; i++)
			{
				a = l->Get_Node(i);
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
			a = l->Get_Node(i);
			xMid += a.GetValue()*a.GetNi();
		}

		xMid = (double)xMid / N;
		R = l->Get_Node(1).GetValue() - l->Get_Node(k).GetValue();

		if (N % 2 != 0)
		{			
			Me = (double)*xkplus1;
		}
		else
		{
			
			Me = (double)(*xk + *xkplus1)*0.5;
		}
		
		for (int i = 1; i <= k; i++)
		{
			a = l->Get_Node(i);
			S2 += (a.GetValue() - xMid)*(a.GetValue() - xMid)*a.GetNi();
		}

		S2 = (double)S2 / N;
			
		int TableIndex = 1;

		for(int i = k; i > 0; i--)
		{						
			a = l->Get_Node(i);
			div = a.GetNi() / (double)N;

			sprintf_s(buffer1, "%d", i);
			sprintf_s(buffer2, "%d", a.GetValue());

			dataGridView1->Columns->Add(gcnew String(buffer1), gcnew String(buffer2));
			dataGridView1->Rows[0]->Cells[TableIndex]->Value = a.GetNi();
			dataGridView1->Rows[1]->Cells[TableIndex]->Value = div;
			dataGridView1->Rows[2]->Cells[TableIndex]->Value = a.GetP();

			if (abs(div - a.GetP()) > MaxSub)
			{
				MaxSub = abs(div - a.GetP());
			}

			TableIndex++;
		}

		xMid = round(xMid * 1000) / 1000;
		S2 = round(S2 * 1000) / 1000;

		dataGridView2->Rows->Add();
		dataGridView2->Rows[0]->Cells[0]->Value = round((1 / p) * 1000) / 1000;
		dataGridView2->Rows[0]->Cells[1]->Value = xMid;
		dataGridView2->Rows[0]->Cells[2]->Value = abs((round((1 / p) * 1000) / 1000) - xMid);
		dataGridView2->Rows[0]->Cells[3]->Value = round(((1 - p) / (p*p)) * 1000) / 1000;
		dataGridView2->Rows[0]->Cells[4]->Value = S2;
		dataGridView2->Rows[0]->Cells[5]->Value = abs((round(((1 - p) / (p*p)) * 1000) / 1000) - S2);
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

		label5->Visible = true;
		textBox3->Visible = true;
		textBox3->ReadOnly = false;
		textBox3->Text = "";
		textBox2->Text = "";
		button2->Visible = true;

		while (index != K)
		{
			Sleep(20);
			Application::DoEvents();
		}

		textBox3->Text = "Массив заполнен";
		textBox3->ReadOnly = true;
		button2->Visible = false;
		label5->Visible = false;

		for (int i = 0; i <= K; i++)
		{
			dataGridView4->Rows->Add();
			dataGridView4->Rows[i]->Cells[0]->Value = i;
			dataGridView4->Rows[i]->Cells[1]->Value = z[i];
		}

		double z_left = z[0], z_right = z[1];

		for (int i = 0; i < K; i++)
		{
			for (int j = k; j > 0; j--)
			{
				a = l->Get_Node(j);
				if (a.GetValue() > z_right)
				{
					break;
				}
				if ((a.GetValue() >= z_left) && (a.GetValue() < z_right))
				{
					nj[i] += a.GetNi();
				}
			}
			z_left = z_right;
			z_right = z[i + 2];
		}

		z_left = z[0];
		z_right = z[1];

		double zfract1, zfract2;
		double zint1, zint2;

		for (int i = 0; i < K - 1; i++) //Итерации от 0 до K - 2 включительно
		{
			zfract1 = modf(z_right, &zint1);
			zfract2 = modf(z_left, &zint2);
			if (z_left >= 1.0)
			{
				if (zfract2 != 0.0)
				{
					if (zfract1 != 0.0)
					{
						for (int j = (int)(zint2)+1; j <= (int)zint1; j++)
						{
							q[i] += p*pow(1 - p, j - 1);
						}
					}
					else
					{
						for (int j = (int)(zint2)+1; j < (int)zint1; j++)
						{
							q[i] += p*pow(1 - p, j - 1);
						}
					}
				}
				else
				{
					if (zfract1 != 0.0)
					{
						for (int j = (int)zint2; j <= (int)zint1; j++)
						{
							q[i] += p*pow(1 - p, j - 1);
						}
					}
					else
					{
						for (int j = (int)(zint2); j < (int)zint1; j++)
						{
							q[i] += p*pow(1 - p, j - 1);
						}
					}
				}
			}
			else
			{
				if (z_right > 1.0)
				{
					if (zfract1 != 0.0)
					{
						for (int j = 1; j <= (int)zint1; j++)
						{
							q[i] += p*pow(1 - p, j - 1);
						}
					}
					else
					{
						for (int j = 1; j < (int)zint1; j++)
						{
							q[i] += p*pow(1 - p, j - 1);
						}
					}
				}
			}
			z_left = z_right;
			z_right = z[i + 2];
		}

		//Итерация K-1 (правая граница - бесконечность)
		z_left = z[K - 1];
		z_right = z[K];
		zfract2 = modf(z_left, &zint2);

		if (zfract2 != 0.0)
		{
			q[K - 1] = pow(1 - p, (int)(zint2)+1);
		}
		else
		{
			q[K - 1] = pow(1 - p, (int)(zint2));
		}

		for (int i = 0; i < K; i++)
		{
			dataGridView3->Rows->Add();
			dataGridView3->Rows[i]->Cells[0]->Value = i;
			dataGridView3->Rows[i]->Cells[1]->Value = q[i];
		}

		for (int i = 0; i < K; i++)
		{
			R0 += (nj[i] - N*q[i])*(nj[i] - N*q[i]) / (N*q[i]);
		}

		for (int i = 0; i < 20; i++)
		{
			Integral = Integral + (fxi(R0*((i - 1) / 20), K - 1) + fxi(R0*i / 20, K - 1))*R0 / 40;
		}

		FR0 = 1 - Integral;
		

		string ref2 = "F(R0)=";
		sprintf_s(buffer2, "%.6lf", FR0);
		ref2 += buffer2;
		ref2 += "\r\n";

		if (FR0 >= Alpha)
		{
			ref2 += "Гипотеза принята";
		}
		else
		{
			ref2 += "Гипотеза отклонена";
		}

		ref2 += "\r\n";
		textBox2->Text = gcnew String(ref2.c_str());

		l->Delete_List();
		delete[]z;
		delete[]q;
		delete[]nj;
	}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
{
	Create_List(N, *l, *xk, *xkplus1, p, backgroundWorker1);
}
private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) 
{
	progressBar1->Value = e->ProgressPercentage;
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) 
{
	progressBar1->Value = 0;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	z[1] = 1.3;

	for (index = 2; index < K; index++)
	{
		z[index] = z[index - 1] * 1.7;
	}
}
private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{
	if (e->KeyChar == (char)Keys::Enter)
	{
		if (index != K)
		{
			z[index] = Convert::ToDouble(textBox3->Text);
			index++;
			textBox3->Text = "";
		}		
	}	
}
};
}
