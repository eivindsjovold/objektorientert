#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

void inputAndPrintInteger(){
	int a;
	cout << "Input desired Integer: \n";
	cin >> a;
	cout << "Your input was:" << a << "\n"; 
}

int inputInteger(){
	int a;
	cout << "Input desired Integer: \n";
	cin >> a;
	return a;
}

int inputIntegerAndPrintSum(){
	int a = inputInteger();
	int b = inputInteger();

	return a + b;
}

bool isOdd(int n){
	if (n % 2 == 0){
		return false;
	}
	return true;
}

void printHumanReadableTime(int s){
	int hours = s / 3600;
	int minutes = (s % 3600) / 60;
	int seconds = s % 60;
	cout << hours << ":" << minutes << ":" << seconds;
}

int sumNumbers(){
	int number;
	int i;
	int temp;
	int sum;

	cout << "Input number of integers to be summed:";
	cin >> number;
	sum = 0;
	for(i = 1; i < number + 1; i++){
		cout << "Enter number " << i << " : \n";
		cin >> temp;
		sum += temp;
	}
	cout << "The sum of your numbers: " << sum << "\n";
	return sum;
}

int sumNumbersIndefinetely(){
	int i;
	int temp;
	int sum;
	int counter;
	sum = 0;
	counter = 1;
	while (true)
	{
		cout << "Enter number " << counter << " : \n";
		cin >> temp;
		if(temp == 0){
			break;
		}
		sum += temp;
		counter += 1;
	}
	cout << "The sum of your numbers: " << sum << "\n";
	return sum;
}
double inputDouble(){
	double input;
	cout << "Input desired double: \n";
	cin >> input;
	return input;
}

double convertValue(double exchange_rate){
	double user_input = inputDouble();
	while(user_input < 0){
		cout << "Please type a positive value: ";
		cin >> user_input;
	}
	double exchange_value = user_input / exchange_rate;
	return exchange_value;
}


void mult_table(){
	int width, height;
	cin >> width;
	cin >> height;
	for(int i = 0; i < height + 1; ++i){
		for(int j = 0; j < width + 1; ++j){
			int result = i*j;
			if( result < 100){
				cout <<	setw(3) << result;
			}
			else if(result >= 100){
				cout << setw(4) << result;
			}
		}
		cout << endl; 
	}
}

double discriminant(double a, double b, double c){
	return (b*b) - 4*a*c;
}
void printRealRoots(double a, double b, double c){
	double temp = discriminant(a,b,c);
	if(temp > 0){
		double x1 = (-b + sqrt(temp))/2*a;
		double x2 = (-b - sqrt(temp))/2*a;
		cout  << "Real solution \n" << x1 << '\n' << x2 << "\n";
	}
	if(temp == 0){
		double x = -b/2*a;
		cout << "one solution \n" << x << "\n";
	}
	else if(temp < 0){
		cout << "no real solution \n";
	}
}

void solveQuadraticEquation(){
	double a;
	double b;
	double c;
	cout << "input a,b,c in a*x^2 + b*x + c \na:";
	cin >> a;
	cout << "b:";
	cin >> b;
	cout << "c:";
	cin >> c;
	printRealRoots(a,b,c);
}


void pythagoras(){
	using namespace Graph_lib;
	int w = 900;
	int h = 600;
	int x1 = 300;
	int y1 = 150;
	int x2 = 450;
	int y2 = x1;

	Simple_window win{Point{100,100},w,h, "Pythagoras"};
	
	Point triangle_1{300,150};
	Point triangle_2{300,300};
	Point triangle_3{450,300};
	Point triangle_4{150,300};
	Point triangle_5{150,150};
	Point triangle_6{600,150};
	Point triangle_7{450,0};
	Point triangle_8{300,450};
	Point triangle_9{450, 450};

	Polygon rv;
	rv.add(triangle_1);
	rv.add(triangle_2);
	rv.add(triangle_3);

	Polygon ls;
	ls.add(triangle_5);
	ls.add(triangle_1);
	ls.add(triangle_2);
	ls.add(triangle_4);

	
	Polygon rs;
	rs.add(triangle_1);
	rs.add(triangle_3);
	rs.add(triangle_6);
	rs.add(triangle_7);

	Polygon bs;
	bs.add(triangle_2);
	bs.add(triangle_3);
	bs.add(triangle_9);
	bs.add(triangle_8);
	
	rv.set_fill_color(Color::black);
	ls.set_fill_color(Color::green);
	rs.set_fill_color(Color::blue);
	bs.set_fill_color(Color::red);
	
	
	win.attach(rv);
	win.attach(ls);
	win.attach(rs);
	win.attach(bs);

	win.wait_for_button();
}

vector<int> calculateBalance(int rate, int year, int balance){
	vector<int> balances(year + 1); 
	for(int i = 0; i < year + 1; ++i){
		double temp = pow(1.0 + (rate/100.0), i);
		balances[i] = balance * temp;
	}
	return balances;
}

void printBalance(vector<int> balance){
	cout << "Year:  Balance: \n";
	for(int i = 0; i < (int)balance.size(); ++i){ 
		cout << i << "   " << balance[i] << "\n";  
	}
}

int main(){
	int user_input = 9999;
	int seconds;
	double exchange_rate = 11.33;
	while(user_input != 0){
		cout << "Please choose function: \n" << "0: Exit \n" << "1: Sum two integers \n" <<  "2: Sum user decided number of integers \n" 
		<< "3: Convert NOK to Pounds \n" << "4: seconds to hr:min:sec \n" << "5: Solve Quadratic Equation \n" << "6: Pythagoras\n7: Print balance\n8: Gangetabell"<< "Input integer to choose function\n";
		cin >> user_input;
		if(user_input == 1){
			sumNumbers();
		}
		else if (user_input == 2){
			sumNumbersIndefinetely();
		}
		else if (user_input == 3){
			double exchange_value = convertValue(exchange_rate);
			cout << setprecision(2) << exchange_value << '\n';
		}
		else if (user_input == 4){
			cout << "Seconds: \n";
			cin >> seconds;
			printHumanReadableTime(seconds);
		}
		else if (user_input == 5){
			solveQuadraticEquation();
		}
		else if(user_input ==6){
			pythagoras();
		}
		else if(user_input == 7){
			int balance, rate, year;
			cout << "Balance:";
			cin >> balance;
			cout << "Rate: "; 
			cin >> rate;
			cout << "Year: ";
			cin >> year; 
			vector<int> balance_vector = calculateBalance(rate,year,balance);
			printBalance(balance_vector);
		}
		else if(user_input == 8){
			mult_table();
		}
		else{
			cout << "Please input a valid number: \n";
		}
	}
	keep_window_open();	
	return 0;
}