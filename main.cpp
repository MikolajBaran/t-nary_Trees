#include <iostream>
#include <fstream>

using namespace std;

int n, t;
fstream file;

void print(int* a, bool f) {
	if(f == false){
		file.open("drzewa.txt", ios::out|ios::app);
	}
	else{
		file.open("drzewa.txt", ios::out);
	}
	cout << '\t';
	for (int i = 0; i < n*t; i++) {
		cout << a[i] << " ";
		file << a[i] << " ";
	}
	cout << endl;
	file << endl;
	file.close();
}

void generate_Z(int* z){
	int i = n-1;
	if(z[i] > i){
		if(z[i] > z[i-1] +1){
			z[i]--;
		}
		else{
			for(i=n-2;i>0;i--){
				if(z[i] > z[i-1] + 1){
					z[i]--;
					for(int j=i+1; j<n; j++){
						z[j] = j*t + 1;
					}
					break;
				}
			}
		}
	}
}

void generate_tree(){
	int cap = n*t;
	int* tree = new int [cap];
	int* Z = new int [n];
	for(int i=0; i<n; i++){
		Z[i] = i*t + 1;
	}
	
	bool first = true;
	
	while(Z[n-1] > n){
		if(!first){
			generate_Z(Z);
		}
		int z_counter = 0;
		for(int i=0; i<cap; i++){
			if(i == Z[z_counter] - 1){
				tree[i] = 1;
				z_counter++;
			}
			else{
				tree[i] = 0;
			}
		}
		print(tree, first);
		first = false;
	}
	
	delete [] tree;
	delete [] Z;
}

int main() {

	cout << "Program do generowania drzew t-narnych o n-1 wierzcholkach wewnetrznych" << endl;
	cout << "Wprowadz liczbe n wierzcholkow: ";
	cin >> n;
	while(!n || n<2){
		cout << "Wprowadzono niepoprawna wartosc. Liczba wierzcholkow n musi byc rowna co najmniej 2 do utworzenia drzewa (korzen i co najmniej jeden wierzcholek wewnetrzny). Sprobuj jeszcze raz." << endl;
		cout << "Wprowadz liczbe n wierzcholkow: ";
		cin >> n;
	}
	cout << "Wprowadz liczbe t dzieci wychodzacych z jednego rodzica: ";
	cin >> t;
	while(!t || t<1){
		cout << "Wprowadzono niepoprawna wartosc. Sprobuj jeszcze raz." << endl;
		cout << "Wprowadz liczbe t dzieci wychodzacych z jednego rodzica: ";
		cin >> t;
	}
	cout << "Generuje drzewo t-narne...\n" << endl;
	generate_tree();
	cout << "\nWyniki generacji zostaly zapisane w pliku drzewa.txt" << endl;
	
	return 0;
}

