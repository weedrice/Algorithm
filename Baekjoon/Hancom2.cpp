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
/* 문단을 추가할 때 배열의 크기를 증가시키는 함수*/
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
/* 해당 문단에 텍스트를 추가하는 함수*/
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
	//body 선언
	Paragraph body;
	//textBoxs 선언
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
/* TextBox 배열의 크기를 조절하는 함수*/
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
	
	if (nowIdx >= 0) { //textBox에 입력할 때
		resizeTextBox();
		if (textBoxs[textPosition.textBoxIndex].AddText(textPosition, text))
			return true;
		else
			return false;
	}
	else { //Body에 입력할 때
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

	std::cout << "body의 첫 번째 paragraph = " << wordProcessor.getBody().getText(0) << std::endl;
	std::cout << "두 번째 textBox의 두 번째 paragraph = " << wordProcessor.getTextBox()[1].getText(1) << std::endl;

	return 0;
}