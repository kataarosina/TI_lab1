#pragma once

#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Ciphers.h"
#include <clocale>

//using namespace std;

namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для View
	/// </summary>
	public ref class View : public System::Windows::Forms::Form
	{
	public:
		View(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			// А НЕТУ ЕГО!!! 
			// 
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~View()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(294, 13);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(408, 177);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(294, 196);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(408, 95);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(294, 297);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(408, 177);
			this->textBox3->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(175, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Исходный текст";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(245, 196);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Ключ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(198, 297);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Шифротекст";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(33, 576);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(255, 81);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Зашифровать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &View::button1_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(294, 480);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(408, 177);
			this->textBox4->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(126, 483);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(162, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Дешифрованный текст";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(23, 138);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(110, 21);
			this->radioButton1->TabIndex = 10;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Столбцовый";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(23, 165);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(222, 21);
			this->radioButton2->TabIndex = 11;
			this->radioButton2->Text = L"Поворачивающаяся решётка";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(23, 192);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(87, 21);
			this->radioButton3->TabIndex = 12;
			this->radioButton3->Text = L"Виженер";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->InitialDirectory = L"C:\\Users\\Fiodor\\Documents\\BSUIR\\TI\\lab1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 28);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Из файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &View::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(129, 317);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 28);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Экспорт в файл";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &View::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(33, 531);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(127, 39);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Расшифровать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &View::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(166, 531);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(122, 39);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Экспорт";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &View::button5_Click);
			// 
			// View
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 673);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"View";
			this->Text = L"View";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		setlocale(LC_ALL, "Russian");

		std::string key = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string message = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string ans, ans_decr;

		if (radioButton1->Checked) {
			std::string messTest = "";
			for (int i = 0; i < message.size(); ++i)
				if ('A' <= message[i] && message[i] <= 'z') {
					messTest += toupper(message[i]);
				}
			message = messTest;

			std::string keyTest = "";
			for (int i = 0; i < key.size(); ++i)
				if ('A' <= key[i] && key[i] <= 'z') {
					keyTest += toupper(key[i]);
				}
			key = keyTest;

			if (!key.size()) {
				MessageBox::Show("Введите ключ!");
				return;
			}

			ans = column_encrypt(message, key);
			ans_decr = column_decrypt(ans, key);
		}
		else if (radioButton2->Checked) {
			if (textBox2->Lines->Length < 4) {
				MessageBox::Show("Введите корректный ключ!");
				return;
			}

			bool **key = new bool*[4];
			for (int i = 0; i < 4; ++i) {
				key[i] = new bool[4];
				System::String^ __line = textBox2->Lines[i];
				std::string line = msclr::interop::marshal_as<std::string>(__line);
				for (int j = 0; j < 4; ++j)
					if (line[j] == '0' || line[j] == '1')
						key[i][j] = line[j] - '0';
					else {
						MessageBox::Show("Введите корректный ключ!");
						return;
					}
			}

			std::string srcmessage = message;
			message = "";
			for (int i = 0; i < srcmessage.size(); ++i)
				if ('A' <= srcmessage[i] && srcmessage[i] <= 'z')
					message += srcmessage[i];


			if (message.size() > 16) {
				ans = "";
				for (int k = 0; k < message.size(); k += 16) {
					std::string tmp_mes = message.substr(k, k + 16);
					std::string tmp_ans = grille_encrypt(tmp_mes, key);
					ans += tmp_ans;
					ans_decr += grille_decrypt(tmp_ans, key);
				}
			}
			else {
				ans = grille_encrypt(message, key);
				ans_decr = grille_decrypt(ans, key);
			}

		}
		else if (radioButton3->Checked) {

			std::string keyTest = "";

			for (int i = 0; i < key.size(); ++i)
				if ('А' <= key[i] && key[i] <= 'я' || key[i] == 'ё' || key[i] == 'Ё') {
					keyTest += toupper(key[i]);
				}

			key = keyTest;

			if (!key.size()) {
				MessageBox::Show("Введите корректный ключ!");
				return;
			}

			ans = vigener_encrypt(message, key);
			ans_decr = vigener_decrypt(ans, key);
		}
		//MessageBox::Show("Введите ключ!");
		
		textBox3->Text = msclr::interop::marshal_as<System::String^>(ans);
		textBox4->Text = msclr::interop::marshal_as<System::String^>(ans_decr);
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		openFileDialog1->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->Text = System::IO::File::ReadAllText(openFileDialog1->FileName);
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		saveFileDialog1->Filter = "Текстовый файл (*.txt)|*.txt";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::IO::File::WriteAllText(saveFileDialog1->FileName, textBox3->Text);
		}
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		setlocale(LC_ALL, "Russian");

		std::string key = msclr::interop::marshal_as<std::string>(textBox2->Text);
		std::string message = msclr::interop::marshal_as<std::string>(textBox3->Text);
		std::string ans_decr;

		if (radioButton1->Checked) {
			std::string messTest = "";
			for (int i = 0; i < message.size(); ++i)
				if ('A' <= message[i] && message[i] <= 'z') {
					messTest += toupper(message[i]);
				}
			message = messTest;

			std::string keyTest = "";
			for (int i = 0; i < key.size(); ++i)
				if ('A' <= key[i] && key[i] <= 'z') {
					keyTest += toupper(key[i]);
				}
			key = keyTest;

			if (!key.size()) {
				MessageBox::Show("Введите ключ!");
				return;
			}

			ans_decr = column_decrypt(message, key);
		}
		else if (radioButton2->Checked) {
			if (textBox2->Lines->Length < 4) {
				MessageBox::Show("Введите корректный ключ!");
				return;
			}

			bool **key = new bool*[4];
			for (int i = 0; i < 4; ++i) {
				key[i] = new bool[4];
				System::String^ __line = textBox2->Lines[i];
				std::string line = msclr::interop::marshal_as<std::string>(__line);
				for (int j = 0; j < 4; ++j)
					if (line[j] == '0' || line[j] == '1')
						key[i][j] = line[j] - '0';
					else {
						MessageBox::Show("Введите корректный ключ!");
						return;
					}
			}

			if (message.size() > 16) {
				for (int k = 0; k < message.size(); k += 16) {
					std::string tmp_mes = message.substr(k, k + 16);
					ans_decr += grille_decrypt(tmp_mes, key);
				}
			}
			else {
				ans_decr = grille_decrypt(message, key);
			}

		}
		else if (radioButton3->Checked) {

			std::string keyTest = "";

			for (int i = 0; i < key.size(); ++i)
				if ('А' <= key[i] && key[i] <= 'я' || key[i] == 'ё' || key[i] == 'Ё') {
					keyTest += toupper(key[i]);
				}

			key = keyTest;

			if (!key.size()) {
				MessageBox::Show("Введите корректный ключ!");
				return;
			}

			ans_decr = vigener_decrypt(message, key);
		}

		textBox4->Text = msclr::interop::marshal_as<System::String^>(ans_decr);
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		saveFileDialog1->Filter = "Текстовый файл (*.txt)|*.txt";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::IO::File::WriteAllText(saveFileDialog1->FileName, textBox4->Text);
		}
	}
};
}

