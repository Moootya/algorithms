// Генерирование последовательности 
#include <iostream>

using namespace std;

int main()
{
	int start;
	int stop;
	cin >> start;
	cin >> stop;

	while (start < stop)
	{
		cout << start << '\n';
		start += 1;
	}
	
	return 0;
}
