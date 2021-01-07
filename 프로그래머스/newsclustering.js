var pattern_eng = /[a-zA-Z][a-zA-Z]/;	 

function solution(str1, str2) {

    let str1Arr = new Array();
    let str2Arr = new Array();
    
    let tempStr = "";
    str1.toUpperCase().split("").forEach((el) => {
        tempStr += el;
    	if(tempStr.length === 2) {
           	if(pattern_eng.test(tempStr)) {
            	str1Arr.push(tempStr);
			};
            tempStr = el;
        } 
	});
    tempStr = "";
    str2.toUpperCase().split("").forEach((el) => {
        tempStr += el;
    	if(tempStr.length === 2) {
           	if(pattern_eng.test(tempStr)) {
            	str2Arr.push(tempStr);
			};
            tempStr = el;
        } 
	});
    
    
    str1Arr.sort();
    str2Arr.sort();
    if(str1Arr.length < str2Arr.length) {
        let tempstr = str2Arr;
        str2Arr = str1Arr;
        str1Arr = tempstr;
	}
    
    let intersaction = new Array();
    let combineResult = str1Arr.length;
    let interNum = 0;
    let beforeStr = "";
    
    let equalCnt = 1;
    let str1ArrIdx = 0;
   	for(let i=0;i<str2Arr.length;++i) {
    	if(i+1 !== str2Arr.length && str2Arr[i] === str2Arr[i+1]) {
            equalCnt++;
            continue;
		} 
        while(str1ArrIdx < str1Arr.length && str1Arr[str1ArrIdx] < str2Arr[i]) {
            str1ArrIdx++;
        }
        if(str2Arr[i] === str1Arr[str1ArrIdx]) {
           	let len = str1Arr.filter((el) => el === str2Arr[i]).length;
            interNum += (len > equalCnt) ? equalCnt : len;
            combineResult += (len >= equalCnt) ? 0 : equalCnt - len;
        	str1ArrIdx += len;
		} else {
            combineResult += equalCnt;
		}
        equalCnt = 1;
	}

    console.log(str1Arr);
    console.log(str2Arr);
    
    let combineNum = combineResult;
    if(combineNum === 0) {
        return 65536;
    }
    console.log(interNum, combineNum);
    var answer = Math.floor(interNum / combineNum * 65536);
    return answer;
}