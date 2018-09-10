#include <bits/stdc++.h>
using namespace std;

bool twop(int n) 
{ 
	if (n<=1) return true;
   return (ceil(log2(n)) == floor(log2(n))); 
} 

void q1a(){

	int n=20;
	long double arr[n];
	for(int i=0;i<n;i++) arr[i]=0;

	long long int iter = 10000000;
	srand(time(NULL));
	clock_t tStart = clock();

	for(int j=0;j<iter;j++){
		for(int i=1;i<n;i++){
			int pos = i;
			while(pos!=0 && pos!=n){
				int delta = (int)(rand())%2;
				if (delta==0) pos--;
				else pos++;
			}
			if (pos==0) {arr[i]+=1;}
		}
	}
	for(int i=1;i<n;i++){
		arr[i]/=iter;
		cout << arr[i] << ' ';
	}
	printf("\n Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}

void q1b(){

	long double p_i[2];
	p_i[0]=0;
	p_i[1]=0;


	long double arr[25];
	for(int l=0;l<25;l++) arr[l]=0;

	long long int iter = 10000;
	long long int steps = 1000000;

	srand(time(NULL));
	clock_t tStart = clock();

	for(int j=0;j<iter;j++){
		for(int i=0;i<2;i++){
			long int pos = pow(10,i);
			long int count = 0;
			while(count<=steps){
				count++;
				int delta = (int)(rand())%2;
				if (delta==0) pos--;
				else pos++;
				if(pos==0) break;
			}
			if (pos==0) {p_i[i]+=1; if(i==1 && count >0){ if (twop(count)==true) arr[(int)log2(count)]++; else arr[(int)log2(count)+1]++ ; }}
		}
	}

	cout << p_i[0]/iter << ' ' << p_i[1]/iter << ' ' << steps << '\n';
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	
	long long int temp = arr[0];

	for(int l=1;l<25;l++){
		temp+=arr[l];
		arr[l]=temp;
	}
	cout << '[';
	for(int l=0;l<25;l++){
		cout << arr[l]/iter << ',' ;
	}
	cout << ']';

	cout << p_i[1];

}

void q2(){

	long double arr[50];
	for(int l=0;l<50;l++) arr[l]=0;

	long double p_i=0;

	long long int iter = 1000;
	long long int steps = 1000000000;

	srand(time(NULL));
	clock_t tStart = clock();

	for(int j=0;j<iter;j++){
		long int posx = 1;
		long int posy = 0;
		long int count = 0;
		while(count<=steps){
			count++;
			int delta = (int)(rand())%4;
			if (delta==0) posx--;
			else if (delta==1) posx++;
			else if (delta==2) posy--;
			else posy++;
			if(posx==0 && posy==0) break;
		}
			if (posx==0 && posy==0) {p_i+=1;  if (twop(count)==true) arr[(int)log2(count)]++; else arr[(int)log2(count)+1]++ ; }
		
	}

	long long int temp = arr[0];

	for(int l=1;l<50;l++){
		temp+=arr[l];
		arr[l]=temp;
	}
	cout << '[';
	for(int l=0;l<50;l++){
		cout << arr[l]/iter << ',' ;
	}
	cout << ']';

	cout << p_i/iter << ' ' << steps << '\n';

	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}

void q3(){


	long double arr[30];
	for(int l=0;l<30;l++) arr[l]=0;

	long double p_i=0;

	long long int iter = 1000;
	long long int steps = 10000000;

	srand(time(NULL));
	clock_t tStart = clock();

	for(int j=0;j<iter;j++){
		long int posx = 1;
		long int posy = 0;
				long int posz = 0;

		long int count = 0;
		while(count<=steps){
						count++;

			int delta = (int)(rand())%6;
			if (delta==0) posx--;
			else if (delta==1) posx++;
			else if (delta==2) posy--;
			else if (delta==3) posy++;
			else if (delta==4) posz--;
			else posz++;
			if(posx==0 && posy==0 & posz==0) break;
		}
			if (posx==0 && posy==0 && posz==0) {p_i+=1;  if (twop(count)==true) arr[(int)log2(count)]++; else arr[(int)log2(count)+1]++ ; }
		
	}

	long long int temp = arr[0];

	for(int l=1;l<30;l++){
		temp+=arr[l];
		arr[l]=temp;
	}
	cout << '[';
	for(int l=0;l<30;l++){
		cout << arr[l]/iter << ',' ;
	}
	cout << ']';

	cout << p_i/iter << ' ' << steps << '\n';

	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}

int main(){

	printf("Enter a/b/c/d corresponding to the questions 1a, 2b, 2, 3 respectively.");

	char c;
	scanf("%c", &c);

	if (c=='a') q1a();
	else if (c=='b') q1b();
	else if (c=='c') q2();
	else if (c=='d') q3();
	else printf("INVALID");

}
