#include <bits/stdc++.h>
using namespace std;

int main() {
	//Initializations
    int n, iter;
    scanf("%d %d", & n, & iter);
    float accuracy[n - 1];
    for (int i = 0; i < (n - 1); i++)
        accuracy[i] = 0;
    srand(time(NULL));
    clock_t tStart = clock();

    for (int it = 0; it < iter; it++) {

    	//Make a skill array having integers from 0 to (n-1) and shuffle it
	    int skill[n];
        for (int x = 0; x < n; x++)
            skill[x] = x;
        for (int i = n; i != 0; i--) {
            int j = rand() % i;
            swap(skill[i], skill[j]);
        }
        int kmax = -1;

        for (int k = 0; k < (n-1); k++) {

        	//Maximum of first k elements in skill array
            kmax = max(kmax, skill[k]);

            if (kmax == (n - 1)) continue;

            int rep = k;
            while (1) {
                if (skill[rep] > kmax) {
                    if (skill[rep] == (n - 1))
                        accuracy[k] += 1;
                    break;
                }
                rep += 1;
            }
        }
    }

    //Get accuracy on a scale of 0 to 1
    for (int i = 0; i < n; i++)
        accuracy[i] /= float(iter);

    float max_accu = *max_element(accuracy, accuracy + n);
    int index = distance(accuracy, max_element(accuracy, accuracy + n));

    printf("Maximum accuracy of %f is obtained at index %d\n", max_accu, index);

    //Write the array to file
    std::ofstream outfile;
    outfile.open("test.txt", std::ios_base::app);
    for(int i=0;i<(n-1);i++) outfile << accuracy[i] << " ";
    outfile << accuracy[n-1];
    outfile.close();

    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}