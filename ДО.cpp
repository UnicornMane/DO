#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <iomanip>
#include <string>
#include <set>

using namespace std;

constexpr int INF = 2e9;

struct node
{
	int left, right;
	int max;
	node* child_left, * child_right;
};

node *build(int left, int right, vector <int>& a)
{
	if (left > right)
	{
		return nullptr;
	}
	node* res = new node;
	res->left = left;
	res->right = right;
	if (left == right)
	{
		res->child_left = nullptr;
		res->child_right = nullptr;
		res->max = a[left];
	}
	else
	{
		int mid = (left + right) / 2;
		res->child_left = build(left, mid, a);
		res->child_right = build(mid + 1, right, a);
		res->max = max(res->child_left->max, res->child_right->max);
	}
	return res;
}

int query(int left, int right, node *root)
{
	if (right < root->left || left > root->right)
	{
		return -INF;
	}
	if (root->left >= left && root->right <= right)
	{
		return root->max;
	}
	return max(query(left, right, root->child_left), query(left, right, root->child_right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector <int> a;

	node* root = build(0, a.size() - 1, a);
}
