#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int strtok(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			return i;
	}

	return -1;
}

vector<string> changeName(vector<string> temp, map<string, string> idMap) {
	vector<string> answer;

	for (vector<string>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
		int idx = (*iter).find("님이");
		string uid = (*iter).substr(0, idx);
		(*iter).replace(0, uid.length(), idMap[uid]);
		answer.push_back(*iter);
	}

	return answer;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> idMap;
	for (vector<string>::iterator iter = record.begin(); iter != record.end(); iter++) {
		//문자열 분리 작업 시작
		int firstSliced = strtok(*iter);
		string cmd = (*iter).substr(0, firstSliced);
		int secondSliced = strtok((*iter).substr(firstSliced + 1, (*iter).length()));
		string uid = (*iter).substr(firstSliced + 1, secondSliced);
		string nickName = (*iter).substr(firstSliced + secondSliced + 2, (*iter).length());
		//문자열 분리 끝
		if (cmd == "Enter") {
			string newStr = uid + "님이 들어왔습니다.";
			answer.push_back(newStr);
			idMap[uid] = nickName;
		}
		else if (cmd == "Leave") {
			string newStr = uid + "님이 나갔습니다.";
			answer.push_back(newStr);
		}
		else {
			idMap[uid] = nickName;
		}
	}

	answer = changeName(answer, idMap);
	return answer;
}

int main() {
	vector<string> record;
	record.push_back("Enter 1 Muzi");
	record.push_back("Enter 2 Prodo");
	record.push_back("Leave 1");
	record.push_back("Enter 1 Prodo");
	record.push_back("Change 2 Ryan");
	record.push_back("Leave 2");
	record.push_back("Enter 3 Apeach");
	record.push_back("Change 3 Kon");
	record.push_back("Enter 2 Ryan");
	record.push_back("Enter 4 Tube");
	record.push_back("Enter 5 Kang");
	record.push_back("Enter 6 Jiwon");
	record.push_back("Change 3 Kim");
	record.push_back("Leave 1");

	vector<string> answer;
	answer = solution(record);
	for (vector<string>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {
		cout << *iter << endl;
	}
}