#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
using namespace System::Runtime::InteropServices; // for STRING^ to char*

namespace Opencv300Test {
	using namespace System;
	using namespace System::IO;
	using namespace System::Reflection;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// <summary>
	/// frmMain ���K�n
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	// �ŧi�p����Ы������ܼ�
	private: Mat *imgC;
	private: VideoCapture *capS;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  tmrCap;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  btnConn;
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pbxS;
	private: System::Windows::Forms::Label^  labFileName;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txbCamID;
	private: System::Windows::Forms::Button^  btnAnalysis;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  txbDecodeResult;
	private: System::Windows::Forms::PictureBox^  pbxQ10;

	private: System::Windows::Forms::PictureBox^  pbxQ09;

	private: System::Windows::Forms::PictureBox^  pbxQ08;

	private: System::Windows::Forms::PictureBox^  pbxQ07;

	private: System::Windows::Forms::PictureBox^  pbxQ06;

	private: System::Windows::Forms::PictureBox^  pbxQ05;

	private: System::Windows::Forms::PictureBox^  pbxQ04;

	private: System::Windows::Forms::PictureBox^  pbxQ03;
	private: System::Windows::Forms::PictureBox^  pbxQ02;
	private: System::Windows::Forms::PictureBox^  pbxQ01;
	private: System::Windows::Forms::PictureBox^  pbxT;

	private: System::Windows::Forms::Label^  labTargetAmount;
	private: System::Windows::Forms::Label^  label15;
	private: System::ComponentModel::IContainer^  components;

	public:
		frmMain(void)
		{
			InitializeComponent();

			// �إ߫�Ы������ܼ�
			imgC = new Mat;
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}

			// �R����Ы������ܼ�
			if (imgC) delete imgC;
			if (capS){ (*capS).release(); delete capS; }
		}

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC

		/// </summary>
		void ShowColorMat2PicBox(System::Windows::Forms::PictureBox^ pBox, cv::Mat& colorImage)
		{
			System::Drawing::Graphics^ graphics = pBox->CreateGraphics();
			System::IntPtr ptr(colorImage.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(
				colorImage.cols,
				colorImage.rows,
				colorImage.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb,
				ptr);
			pBox->Image = b;
			pBox->Update();
		}
		/*************************************************************************************/

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tmrCap = (gcnew System::Windows::Forms::Timer(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->labTargetAmount = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->btnAnalysis = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbDecodeResult = (gcnew System::Windows::Forms::RichTextBox());
			this->pbxQ10 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ09 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ08 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ07 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ06 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ05 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ04 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ03 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ02 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxQ01 = (gcnew System::Windows::Forms::PictureBox());
			this->pbxT = (gcnew System::Windows::Forms::PictureBox());
			this->labFileName = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txbCamID = (gcnew System::Windows::Forms::TextBox());
			this->btnConn = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pbxS = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ09))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ08))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ07))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ06))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ05))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ04))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ03))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ02))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ01))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxS))->BeginInit();
			this->SuspendLayout();
			//
			// tmrCap
			//
			this->tmrCap->Interval = 33;
			this->tmrCap->Tick += gcnew System::EventHandler(this, &frmMain::tmrL_Tick);
			//
			// openFileDialog1
			//
			this->openFileDialog1->FileName = L"openFileDialog1";
			//
			// tabControl1
			//
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(12, 30);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1240, 580);
			this->tabControl1->TabIndex = 8;
			//
			// tabPage1
			//
			this->tabPage1->Controls->Add(this->labTargetAmount);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->btnAnalysis);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->pbxT);
			this->tabPage1->Controls->Add(this->labFileName);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->txbCamID);
			this->tabPage1->Controls->Add(this->btnConn);
			this->tabPage1->Controls->Add(this->btnLoad);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->pbxS);
			this->tabPage1->Location = System::Drawing::Point(4, 28);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1232, 548);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Capture";
			this->tabPage1->UseVisualStyleBackColor = true;
			//
			// labTargetAmount
			//
			this->labTargetAmount->BackColor = System::Drawing::Color::Aquamarine;
			this->labTargetAmount->Location = System::Drawing::Point(1020, 38);
			this->labTargetAmount->Name = L"labTargetAmount";
			this->labTargetAmount->Size = System::Drawing::Size(38, 19);
			this->labTargetAmount->TabIndex = 40;
			this->labTargetAmount->Text = L"0";
			this->labTargetAmount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// label15
			//
			this->label15->Location = System::Drawing::Point(959, 38);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(64, 19);
			this->label15->TabIndex = 39;
			this->label15->Text = L"Target :";
			//
			// btnAnalysis
			//
			this->btnAnalysis->Enabled = false;
			this->btnAnalysis->Location = System::Drawing::Point(968, 233);
			this->btnAnalysis->Name = L"btnAnalysis";
			this->btnAnalysis->Size = System::Drawing::Size(90, 45);
			this->btnAnalysis->TabIndex = 38;
			this->btnAnalysis->Text = L"Analysis";
			this->btnAnalysis->UseVisualStyleBackColor = true;
			this->btnAnalysis->Click += gcnew System::EventHandler(this, &frmMain::btnAnalysis_Click);
			//
			// groupBox2
			//
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->txbDecodeResult);
			this->groupBox2->Controls->Add(this->pbxQ10);
			this->groupBox2->Controls->Add(this->pbxQ09);
			this->groupBox2->Controls->Add(this->pbxQ08);
			this->groupBox2->Controls->Add(this->pbxQ07);
			this->groupBox2->Controls->Add(this->pbxQ06);
			this->groupBox2->Controls->Add(this->pbxQ05);
			this->groupBox2->Controls->Add(this->pbxQ04);
			this->groupBox2->Controls->Add(this->pbxQ03);
			this->groupBox2->Controls->Add(this->pbxQ02);
			this->groupBox2->Controls->Add(this->pbxQ01);
			this->groupBox2->Location = System::Drawing::Point(628, 286);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(598, 255);
			this->groupBox2->TabIndex = 37;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"QR Code";
			//
			// label14
			//
			this->label14->Location = System::Drawing::Point(436, 25);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(156, 19);
			this->label14->TabIndex = 21;
			this->label14->Text = L"Decode Result:";
			//
			// label9
			//
			this->label9->Location = System::Drawing::Point(350, 138);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(80, 19);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Code #10";
			//
			// label10
			//
			this->label10->Location = System::Drawing::Point(264, 138);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(80, 19);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Code #9";
			//
			// label11
			//
			this->label11->Location = System::Drawing::Point(178, 138);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(80, 19);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Code #8";
			//
			// label12
			//
			this->label12->Location = System::Drawing::Point(92, 138);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(80, 19);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Code #7";
			//
			// label13
			//
			this->label13->Location = System::Drawing::Point(6, 138);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(80, 19);
			this->label13->TabIndex = 16;
			this->label13->Text = L"Code #6";
			//
			// label8
			//
			this->label8->Location = System::Drawing::Point(350, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(80, 19);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Code #5";
			//
			// label7
			//
			this->label7->Location = System::Drawing::Point(264, 25);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 19);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Code #4";
			//
			// label6
			//
			this->label6->Location = System::Drawing::Point(178, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 19);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Code #3";
			//
			// label4
			//
			this->label4->Location = System::Drawing::Point(92, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 19);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Code #2";
			//
			// label2
			//
			this->label2->Location = System::Drawing::Point(6, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 19);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Code #1";
			//
			// txbDecodeResult
			//
			this->txbDecodeResult->Location = System::Drawing::Point(436, 47);
			this->txbDecodeResult->Name = L"txbDecodeResult";
			this->txbDecodeResult->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->txbDecodeResult->Size = System::Drawing::Size(156, 193);
			this->txbDecodeResult->TabIndex = 10;
			this->txbDecodeResult->Text = L"";
			//
			// pbxQ10
			//
			this->pbxQ10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ10->Location = System::Drawing::Point(350, 160);
			this->pbxQ10->Name = L"pbxQ10";
			this->pbxQ10->Size = System::Drawing::Size(80, 80);
			this->pbxQ10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ10->TabIndex = 9;
			this->pbxQ10->TabStop = false;
			//
			// pbxQ09
			//
			this->pbxQ09->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ09->Location = System::Drawing::Point(264, 160);
			this->pbxQ09->Name = L"pbxQ09";
			this->pbxQ09->Size = System::Drawing::Size(80, 80);
			this->pbxQ09->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ09->TabIndex = 8;
			this->pbxQ09->TabStop = false;
			//
			// pbxQ08
			//
			this->pbxQ08->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ08->Location = System::Drawing::Point(178, 160);
			this->pbxQ08->Name = L"pbxQ08";
			this->pbxQ08->Size = System::Drawing::Size(80, 80);
			this->pbxQ08->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ08->TabIndex = 7;
			this->pbxQ08->TabStop = false;
			//
			// pbxQ07
			//
			this->pbxQ07->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ07->Location = System::Drawing::Point(92, 160);
			this->pbxQ07->Name = L"pbxQ07";
			this->pbxQ07->Size = System::Drawing::Size(80, 80);
			this->pbxQ07->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ07->TabIndex = 6;
			this->pbxQ07->TabStop = false;
			//
			// pbxQ06
			//
			this->pbxQ06->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ06->Location = System::Drawing::Point(6, 160);
			this->pbxQ06->Name = L"pbxQ06";
			this->pbxQ06->Size = System::Drawing::Size(80, 80);
			this->pbxQ06->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ06->TabIndex = 5;
			this->pbxQ06->TabStop = false;
			//
			// pbxQ05
			//
			this->pbxQ05->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ05->Location = System::Drawing::Point(350, 47);
			this->pbxQ05->Name = L"pbxQ05";
			this->pbxQ05->Size = System::Drawing::Size(80, 80);
			this->pbxQ05->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ05->TabIndex = 4;
			this->pbxQ05->TabStop = false;
			//
			// pbxQ04
			//
			this->pbxQ04->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ04->Location = System::Drawing::Point(264, 47);
			this->pbxQ04->Name = L"pbxQ04";
			this->pbxQ04->Size = System::Drawing::Size(80, 80);
			this->pbxQ04->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ04->TabIndex = 3;
			this->pbxQ04->TabStop = false;
			//
			// pbxQ03
			//
			this->pbxQ03->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ03->Location = System::Drawing::Point(178, 47);
			this->pbxQ03->Name = L"pbxQ03";
			this->pbxQ03->Size = System::Drawing::Size(80, 80);
			this->pbxQ03->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ03->TabIndex = 2;
			this->pbxQ03->TabStop = false;
			//
			// pbxQ02
			//
			this->pbxQ02->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ02->Location = System::Drawing::Point(92, 47);
			this->pbxQ02->Name = L"pbxQ02";
			this->pbxQ02->Size = System::Drawing::Size(80, 80);
			this->pbxQ02->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ02->TabIndex = 1;
			this->pbxQ02->TabStop = false;
			//
			// pbxQ01
			//
			this->pbxQ01->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbxQ01->Location = System::Drawing::Point(6, 47);
			this->pbxQ01->Name = L"pbxQ01";
			this->pbxQ01->Size = System::Drawing::Size(80, 80);
			this->pbxQ01->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxQ01->TabIndex = 0;
			this->pbxQ01->TabStop = false;
			//
			// pbxT
			//
			this->pbxT->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbxT->Location = System::Drawing::Point(628, 38);
			this->pbxT->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pbxT->Name = L"pbxT";
			this->pbxT->Size = System::Drawing::Size(320, 240);
			this->pbxT->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxT->TabIndex = 36;
			this->pbxT->TabStop = false;
			//
			// labFileName
			//
			this->labFileName->BackColor = System::Drawing::Color::PaleGreen;
			this->labFileName->Location = System::Drawing::Point(242, 6);
			this->labFileName->Name = L"labFileName";
			this->labFileName->Size = System::Drawing::Size(280, 27);
			this->labFileName->TabIndex = 21;
			this->labFileName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			//
			// label5
			//
			this->label5->Location = System::Drawing::Point(185, 5);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 27);
			this->label5->TabIndex = 20;
			this->label5->Text = L"File :";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			//
			// label3
			//
			this->label3->Location = System::Drawing::Point(522, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 27);
			this->label3->TabIndex = 16;
			this->label3->Text = L"ID : ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			//
			// txbCamID
			//
			this->txbCamID->Location = System::Drawing::Point(579, 6);
			this->txbCamID->Name = L"txbCamID";
			this->txbCamID->Size = System::Drawing::Size(28, 27);
			this->txbCamID->TabIndex = 15;
			this->txbCamID->Text = L"0";
			this->txbCamID->TextChanged += gcnew System::EventHandler(this, &frmMain::txbCamIDL_TextChanged);
			//
			// btnConn
			//
			this->btnConn->Location = System::Drawing::Point(7, 496);
			this->btnConn->Name = L"btnConn";
			this->btnConn->Size = System::Drawing::Size(90, 45);
			this->btnConn->TabIndex = 14;
			this->btnConn->Text = L"Connect";
			this->btnConn->UseVisualStyleBackColor = true;
			this->btnConn->Click += gcnew System::EventHandler(this, &frmMain::btnConnL_Click);
			//
			// btnLoad
			//
			this->btnLoad->Location = System::Drawing::Point(103, 496);
			this->btnLoad->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(90, 45);
			this->btnLoad->TabIndex = 11;
			this->btnLoad->Text = L"Load...";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &frmMain::btnLoadL_Click);
			//
			// label1
			//
			this->label1->Location = System::Drawing::Point(6, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 27);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Cam";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// pbxS
			//
			this->pbxS->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pbxS->Location = System::Drawing::Point(7, 38);
			this->pbxS->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pbxS->Name = L"pbxS";
			this->pbxS->Size = System::Drawing::Size(600, 450);
			this->pbxS->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbxS->TabIndex = 7;
			this->pbxS->TabStop = false;
			//
			// frmMain
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 642);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"frmMain";
			this->Text = L"QR Code Tracker by Jack Hsu";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ09))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ08))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ07))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ06))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ05))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ04))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ03))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ02))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxQ01))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxS))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void btnConnL_Click(System::Object^  sender, System::EventArgs^  e) {

	if (btnConn->Text == "Connect"){
		labFileName->Text = "";
		int camID = Int32::Parse(txbCamID->Text);
		capS = new VideoCapture(CAP_DSHOW + camID);

		if ((*capS).isOpened()){
			tmrCap->Enabled = true;
			btnConn->Text = "Dis-Conn";
			(*capS) >> (*imgC);
		}
		else{
			MessageBox::Show("�䤣��@����v��!");
			exit(0);
		}
	}
	else{
		btnConn->Text = "Connect";
		tmrCap->Enabled = false;
		if (capS){ (*capS).release(); delete capS; capS = nullptr; }
	}
}
private: System::Void btnLoadL_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		labFileName->Text = Path::GetFileName(openFileDialog1->FileName);
		btnConn->Text = "Connect";
		tmrCap->Enabled = false;
		if (capS){ (*capS).release(); delete capS; capS = nullptr; }

		*imgC = imread((char*)(void*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName), IMREAD_COLOR);

		if ((*imgC).data){
			ShowColorMat2PicBox(pbxS, *imgC);
			btnAnalysis->Enabled = true;
		}
		else{
			MessageBox::Show("�ɮ׶}�ҿ�~!");
		}
	}
}

private: System::Void txbCamIDL_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	btnConn->Text = "Connect";
	tmrCap->Enabled = false;
	if (capS){ (*capS).release(); delete capS; capS = nullptr; }
}

private: System::Void tmrL_Tick(System::Object^  sender, System::EventArgs^  e) {
	//Mat img;

	(*capS) >> (*imgC);

	if ((*capS).read(*imgC) != 0){
		//GaussianBlur((*imgCL), img, cv::Size(3, 3), 1.5, 1.5);
		//flip(img, img, 1);
		ShowColorMat2PicBox(pbxS, *imgC);
	}
	else{
		MessageBox::Show("�䤣����v��!");
		exit(0);
	}
}

private: System::Void btnAnalysis_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat matColor,matBin;
	vector<Mat> planes;

	txbDecodeResult->Clear();

	// todo 只需要這一行
	cvtColor((*imgC), matColor, COLOR_BGR2YCrCb); // 將色彩空間從RGB轉到YCrCb

    //todo planes 分成  Y , Cr , Cb分別存於   planes[0],planes[1],planes[2]裡面，在本範例中 我們取 planes[2]的 br
	split(matColor, planes); // 分離彩色通道

	//todo 此處判定藍色筐的顏色界定 Cb的藍色值 144~255 只是此處的範例
	threshold(planes[2], matBin, 144, 255, THRESH_BINARY); //  Cb通道2，門檻值144。

    //todo 取四個點 ，contours
    vector<vector<cv::Point>> contours;


	findContours(matBin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE); //  只取外輪廓

	// 隨機著色
	//todo 此處照貼--------------------------- start
	RNG rng(12345);
	vector<vector<cv::Point>> poly(contours.size());
	vector<vector<cv::Point>> marker;
	matColor = Mat::zeros(matColor.size(), CV_8UC3);

	for (int i = 0; i < contours.size(); i++){
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), 128); //保留一位數避免全都是零
		double eps = contours[i].size()*0.05;

		approxPolyDP(contours[i], poly[i], eps, true); //  找出近似多邊形

		if (poly[i].size() != 4) // 若輪廓非四點則放棄
			continue;

		if (!isContourConvex(poly[i])) // 若非外凸形狀則放棄
			continue;

		drawContours(matColor, contours, i, color, FILLED, 8);

		if (abs(poly[i][0].x - poly[i][2].x) < 1.3 * abs(poly[i][0].y - poly[i][2].y)) { // 正常長寬比應小於1.3倍
			drawContours(matColor, poly, i, Scalar(0, 0, 255), 2, 8, vector<Vec4i>(), 0, cv::Point());
			marker.push_back(poly[i]);
		}
		else{
			drawContours(matColor, poly, i, Scalar(255, 0, 0), 2, 8, vector<Vec4i>(), 0, cv::Point());
		}
	}
	//todo 此處照貼--------------------------- End

	//todo 忽略-------------start
	array<PictureBox^>^ arrayPicBox = gcnew array<PictureBox^>(10);

	arrayPicBox[0] = pbxQ01; arrayPicBox[1] = pbxQ02; arrayPicBox[2] = pbxQ03; arrayPicBox[3] = pbxQ04; arrayPicBox[4] = pbxQ05;
	arrayPicBox[5] = pbxQ06; arrayPicBox[6] = pbxQ07; arrayPicBox[7] = pbxQ08; arrayPicBox[8] = pbxQ09; arrayPicBox[9] = pbxQ10;
	//todo 忽略-------------End

	for (int i = 0; i < 10; i++){
		Mat z = Mat::zeros(80, 80, CV_8UC3);
		ShowColorMat2PicBox(arrayPicBox[i], z);
	}

	Point2f ptsT[] = { cv::Point2f(0, 0), cv::Point2f(0, 79), cv::Point2f(79, 79), cv::Point2f(79, 0) };

	for (size_t i = 0; i < marker.size(); i++){
		Point2f ptsS[] = { cv::Point2f(marker[i][0].x, marker[i][0].y),
			cv::Point2f(marker[i][1].x, marker[i][1].y),
			cv::Point2f(marker[i][2].x, marker[i][2].y),
			cv::Point2f(marker[i][3].x, marker[i][3].y) };
		Mat m = getPerspectiveTransform(ptsS, ptsT);
		Mat matResult = Mat::zeros(80, 80, CV_8UC3);

		warpPerspective(*imgC, matResult, m, matResult.size(), INTER_LINEAR);
		ShowColorMat2PicBox(arrayPicBox[i], matResult);

		System::String ^tempS = i.ToString() + ": " +
			"(" + marker[i][0].x.ToString() + "," + marker[i][0].y.ToString() + ")," +
			"(" + marker[i][1].x.ToString() + "," + marker[i][1].y.ToString() + ")," +
			"(" + marker[i][2].x.ToString() + "," + marker[i][2].y.ToString() + ")," +
			"(" + marker[i][3].x.ToString() + "," + marker[i][3].y.ToString() + ")," +
			"\n";
		txbDecodeResult->AppendText(tempS);
	}

	labTargetAmount->Text = marker.size().ToString();
	ShowColorMat2PicBox(pbxT, matColor); // 顯示Cb通道
}
};
}
