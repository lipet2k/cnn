#include <iostream>
#include <tuple>
#include <fstream>
using namespace std;

int main() {
    const int NUM_DATA = 100;
    const int IMAGE_SIZE = 3072;

    int c_labels[NUM_DATA];
    int f_labels[NUM_DATA];
    int images[NUM_DATA][IMAGE_SIZE];

    ifstream infile("data/cifar-100-binary/test.bin", ifstream::binary);


    for (int i=0;i<NUM_DATA;++i) {
        char coarse_label;
        infile.read(&coarse_label, sizeof(coarse_label));
        c_labels[i] = coarse_label;
        
        char fine_label;
        infile.read(&fine_label, sizeof(fine_label));
        f_labels[i] = fine_label;

        char arr[IMAGE_SIZE];
        infile.read(arr, sizeof(arr));

        for(int j=0;j<IMAGE_SIZE;++j) {
           images[i][j] = arr[j];
        }
    }

    infile.close(); 
    for (int i = 0; i < NUM_DATA; ++i)
        cout << images[i][100] << "\n";
    return 0;

}
