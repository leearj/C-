//Lee Jaeseung
//HW4-ex4
//Completed: 2016/01/29

using namespace std;
int*** alloc3D(int x, int y, int z);
void dealloc3D(int*** a, int x, int y);

int main() {
	while (true) {
		int*** arr = alloc3D(100, 100, 100);
		dealloc3D(arr, 100, 100);
	}
	return 0;
}
//TASK: allocate a given 3d array of ints with the dimensions passed as arugments.
int*** alloc3D(int x, int y, int z) {
	//Allocating 3D-array memory of ints.
	int*** ipppArr = new int**[x];
	for (int i = 0; i < x; ++i) {
		ipppArr[i] = new int*[y];
		for (int j = 0; j < y; ++j) {
			ipppArr[i][j] = new int[z];
		}
	}
	return ipppArr;
}
//TASK: deallocate a given 3D of ints with the dimensions passed as arugments.
void dealloc3D(int*** arr, int x, int y) {
	//a = new int**[x];
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			delete[] arr[i][j];
			arr[i][j] = nullptr;
		}
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;

}