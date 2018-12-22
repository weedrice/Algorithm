#include <iostream>
#include <string>

struct TextPosition {
	int textBoxIndex;
	unsigned int paragraphIndex;
	unsigned int textOffset;
};

class Paragraph {
public:
	static const int CAPACITY_UNIT = 20;

	Paragraph();
	bool AddText(const TextPosition& textPosition, const std::string& text);
	std::string getText(int i);
	int getParagraphIdx();

private:
	std::string* text;
	int paragraphIdx = 0;

	void resizeParagraph(const TextPosition& textPosition);
};

Paragraph::Paragraph() {
	this->text = new std::string[this->paragraphIdx + 1];
}
/* ������ �߰��� �� �迭�� ũ�⸦ ������Ű�� �Լ�*/
void Paragraph::resizeParagraph(const TextPosition& textPosition) {
	if (this->paragraphIdx < textPosition.paragraphIndex) {
		std::string* temp = new std::string[textPosition.paragraphIndex+1];
		for (int i = 0; i <= paragraphIdx; i++)
			temp[i] = this->text[i];
		delete[] this->text;
		this->text = temp;
		this->paragraphIdx = textPosition.paragraphIndex;
	}
}
/* �ش� ���ܿ� �ؽ�Ʈ�� �߰��ϴ� �Լ�*/
bool Paragraph::AddText(const TextPosition& textPosition, const std::string& text) {
	resizeParagraph(textPosition);
	int nowParagraph = textPosition.paragraphIndex;

	if (textPosition.textOffset > this->text[nowParagraph].length()) {
		return false;
	}

	this->text[nowParagraph].insert(textPosition.textOffset, text);
	return true;
}
std::string Paragraph::getText(int i) {
	return this->text[i];
}
int Paragraph::getParagraphIdx() {
	return this->paragraphIdx;
}

class Application {
public:
	TextPosition& GetTextPosition();

	Application();
	virtual bool AddText(const std::string& text) = 0;

protected:
	TextPosition textPosition;
};

Application::Application() {
	textPosition.textOffset = 0;
	textPosition.textBoxIndex = -1;
	textPosition.paragraphIndex = 0;
}
TextPosition& Application::GetTextPosition() {
	return this->textPosition;
}

class WordProcessor : public Application {
public:
	WordProcessor();
	virtual bool AddText(const std::string& text);
	int getTextBoxIdx();
	Paragraph getBody();
	Paragraph* getTextBox();

private:
	//body ����
	Paragraph body;
	//textBoxs ����
	Paragraph* textBoxs;
	int textBoxIdx = 0;
	void resizeTextBox();
};

WordProcessor::WordProcessor() {
	textBoxs = new Paragraph[this->textBoxIdx+1];
}
int WordProcessor::getTextBoxIdx() {
	return this->textBoxIdx;
}
Paragraph WordProcessor::getBody() {
	return this->body;
}
Paragraph* WordProcessor::getTextBox() {
	return this->textBoxs;
}
/* TextBox �迭�� ũ�⸦ �����ϴ� �Լ�*/
void WordProcessor::resizeTextBox() {
	int checkIdx = this->textPosition.textBoxIndex;
	if (checkIdx > this->textBoxIdx) {
		Paragraph* temp = new Paragraph[checkIdx+1];
		for (int i = 0; i <= this->textBoxIdx; i++)
			temp[i] = this->textBoxs[i];
		delete[] this->textBoxs;
		this->textBoxs = temp;
		this->textBoxIdx = checkIdx;
	}
}
bool WordProcessor::AddText(const std::string& text) {
	int nowIdx = this->textPosition.textBoxIndex;
	
	if (nowIdx >= 0) { //textBox�� �Է��� ��
		resizeTextBox();
		if (textBoxs[textPosition.textBoxIndex].AddText(textPosition, text))
			return true;
		else
			return false;
	}
	else { //Body�� �Է��� ��
		if (body.AddText(this->textPosition, text))
			return true;
		else
			return false;
	}
}

int main(int argc, char* argv[]) {
	WordProcessor wordProcessor;
	TextPosition& textPosition = wordProcessor.GetTextPosition();

	wordProcessor.AddText("ccccc");
	wordProcessor.AddText("bbbbb");
	wordProcessor.AddText("aaaaa");

	textPosition.textBoxIndex = 1;
	textPosition.paragraphIndex = 1;
	textPosition.textOffset = 0;
	wordProcessor.AddText("aaaaa");

	textPosition.textOffset = 2;
	wordProcessor.AddText("bbbbb");

	textPosition.textOffset = 4;
	wordProcessor.AddText("ccccc");

	std::cout << "body�� ù ��° paragraph = " << wordProcessor.getBody().getText(0) << std::endl;
	std::cout << "�� ��° textBox�� �� ��° paragraph = " << wordProcessor.getTextBox()[1].getText(1) << std::endl;

	return 0;
}