#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  // Write your code here.
	int left_node = 0;
	int right_node = array.size()-1;
	int mid_node = (right_node - left_node)/2;
	
	int index = -1;
	
	while (right_node>=left_node){
		if( array[mid_node]==target)
			return mid_node;
		else if (target>array[mid_node]){
			left_node = mid_node + 1;
			mid_node = (right_node + left_node)/2;
		}
		else{		
			right_node = mid_node - 1;
			mid_node = (right_node + left_node)/2;
		}
	}
  return index;
}
