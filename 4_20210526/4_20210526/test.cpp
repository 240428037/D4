//快速排序（从小到大）
void quickSort(int left, int right, vector<int>& arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}


class Solution {
public:
	int partsort(vector<int>&nums, int left, int right){
		//right作key left先走
		int key = nums[right];
		int keyindex = right;
		while (left < right){
			//<=和>=不加=会死循环 5-最左 5 5-最右 三个数永远动不了
			//left找大-找到出while
			while (left < right&&nums[left] <= key){
				left++;
			}
			//right找小-找到出while
			while (left < right&&nums[right] >= key){
				right--;
			}
			//交换
			swap(nums[left], nums[right]);
		}
		swap(nums[left], nums[keyindex]);
		return left;//返回相遇的位置
	}
	void quicksort(vector<int>&nums, int left, int right){
		if (left >= right){
			return;//这个区间没有值了 不用排了 return 
		}
		int pos = partsort(nums, left, right);
		quicksort(nums, left, pos - 1);
		quicksort(nums, pos + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort(nums, left, right);
		return nums;
	}
};