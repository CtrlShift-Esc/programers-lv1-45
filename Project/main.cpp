#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> p1 = { 1, 2, 3, 4, 5 };
	vector<int> p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	unordered_map<int, int> score = { {1,0}, {2, 0}, {3, 0} };

	for (int i = 0; i < answers.size(); i++)
	{
		if (p1[i % p1.size()] == answers[i])
			score[1]++;
		if (p2[i % p2.size()] == answers[i])
			score[2]++;
		if (p3[i % p3.size()] == answers[i])
			score[3]++;
	}

	vector<pair<int, int>> vt(score.begin(), score.end());
	sort(vt.begin(), vt.end(), cmp);
	for (auto v : vt)
	{
		if (vt[0].second != v.second)
			continue;
		answer.push_back(v.first);
	}

	return answer;
}

void main()
{
	//test
	//auto ret = solution({1,3,2,4,2});
}