function insertionSort(arr) {

  for(let i=1;i<arr.length;++i) {
    for(let j=i;j>=1;--j) {
      if(arr[j] <= arr[j-1]) {
        let temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      } else {
        break;
      }
    }
  }
  console.log(arr);
}

let array = [4,2,7,3,4,5,6,7,8,1,1,1,1,1,2,3,4,20,3,5,1];

insertionSort(array);