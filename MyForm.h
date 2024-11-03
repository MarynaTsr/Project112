#pragma once

namespace Project112 {

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 84);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть кількість елементів";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(44, 110);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(227, 110);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 48);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Обчислити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(355, 110);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 48);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Очистити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->TextChanged += gcnew System::EventHandler(this, &MyForm::button2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 287);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Результат";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(134, 193);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(124, 156);
			this->textBox2->TabIndex = 5;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(26, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(418, 60);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 361);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Очищення Textbox2 перед обчисленням
		textBox2->Clear();

		// Перевірка, чи введено число
		int n;
		if (!Int32::TryParse(textBox1->Text, n) || n <= 0) {
			textBox2->Text = "Будь ласка, введіть додатнє число.";
			return;
		}

		// Створити масив для зберігання елементів послідовності
		array<int>^ sequence = gcnew array<int>(n);
		sequence[0] = 1;

		// Якщо кількість елементів більше 1, задати другий елемент
		if (n > 1) {
			sequence[1] = 1;
		}

		// Обчислення елементів послідовності за формулою
		for (int i = 2; i < n; i++) {
			sequence[i] = 3 * sequence[i - 1] + 2 * sequence[i - 2] - 1;
		}

		// Виведення результатів у Textbox2
		for (int i = 0; i < n; i++) {
			textBox2->AppendText(sequence[i] + Environment::NewLine);
		}
	}
private: System::Void button2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	// Очищення полів TextBox1 і TextBox2
	TextBox1->Clear();
	TextBox2->Clear();
}
}
};
}
