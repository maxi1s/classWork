#pragma once
namespace Factorial {

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
	private: System::Windows::Forms::Label^ lblInput;
	private: System::Windows::Forms::TextBox^ txtInput;
	private: System::Windows::Forms::Button^ btnCalculate;
	protected:

	protected:


	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::TextBox^ txtOutput;

	private: System::Windows::Forms::Label^ lblOutput;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Location = System::Drawing::Point(24, 61);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(128, 13);
			this->lblInput->TabIndex = 0;
			this->lblInput->Text = L"¬ведите целое число(N)";
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(176, 58);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(87, 20);
			this->txtInput->TabIndex = 1;
			// 
			// btnCalculate
			// 
			this->btnCalculate->Location = System::Drawing::Point(188, 139);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(75, 23);
			this->btnCalculate->TabIndex = 2;
			this->btnCalculate->Text = L"¬ычислить";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Location = System::Drawing::Point(73, 89);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(79, 13);
			this->lblOutput->TabIndex = 3;
			this->lblOutput->Text = L"–езультат (N!)";
			// 
			// txtOutput
			// 
			this->txtOutput->Location = System::Drawing::Point(176, 86);
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ReadOnly = true;
			this->txtOutput->Size = System::Drawing::Size(192, 20);
			this->txtOutput->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 317);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->lblOutput);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->lblInput);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"‘акториал";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		 void ClearAll() {//очистка полей
			 this->txtOutput->Text = "";
			 errorProvider1->SetError(txtInput, String::Empty);
			
		}

 private: System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
	 ClearAll();
	 long long InputNumber;
	 bool result = Int64::TryParse(this->txtInput->Text, InputNumber); //переводим строку из TextBox в число

		 if (!result) //dвели не число
		 errorProvider1->SetError(txtInput, "¬ведено не целое число");
	 else {//число
		 if (InputNumber > 20)
			 this->txtOutput->Text = "—лишком большое число";
		 else {
			 long long OutputNumber = fact(InputNumber);//результат
			 if (OutputNumber == -1) //отрицательное число
				 errorProvider1->SetError(txtInput, "¬ведено отрицательное число");
			 else //все нормально
				 this->txtOutput->Text = System::Convert::ToString(OutputNumber);//записываем в поле вывода
		}
		
	}
	
}
};
}
