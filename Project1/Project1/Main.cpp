#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

void main(){
	string input;
	int num;
	vector <int> IntVector(99,0);

	do {
		cout << "Enter a number to divide 100 by. (Enter 999 to stop)" << endl;
		cout << "Enter a number :";
		cin >> input;

		try {
			//if you enter a non number the exception& will catch it
			num = stoi(input); 

			// if you enter a zero i throw the string cant divide by zero
			if (num == 0) {
				string temp = "Cannot divide by zero";
				throw temp;
			}
			//if its negitive i throw the string enter a positive
			else if (num < 0) {
				string s = "Please enter a positive number";
				throw s;
			}
			else {
				cout << "100/" << num << " is " << (100 / num) << endl;
			}

			// then if their num is below 100 i try to add it to the vector and if its 99 you get an out of range exception
			if (num < 100) {
				
				if (num == 99) {
					string v = "Out of range please use another number";
					throw v;
				}
				else {
					IntVector[num] = num;
				}
				throw num;
			}
		}
		//catches that get stings or ints just out put then to the consol
		catch (string message) {
			cout << message << endl;
		}
		catch (char * message) {
			cout << message << endl;
		}
		catch (int i) {
			cout << i << endl;
		}
		//this catches things that i didnt specify like out of range and couts what it is
		catch (exception& e) {
			cout << e.what() << endl;
		}

		// this trys to catch anything else
		catch (...) {
			cout << "Other Execption was found" << endl;
		}
	} while (num != 999);
	system("pause");
}