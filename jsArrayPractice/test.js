// 변수란

// let a = 10;
// let b = 12;
// let c = a + b;
// console.log(c);

// 자바스크립트의 데이터 타입
// 7개

1 - // 숫자
  1,
  0,
  1;
1.1, -1.1;
0, -0;

// "문자열" // 문자열
// '문자열' // <'안녕하세요'>
// '<\'안녕하세요\'>'
// "문자열", "<'안녕하세요'>"
// `문자열`

// let a = 3;
// let b = 2;
// let str = 'a는 3이고 b는 2다';
// let str1 = 'a는 ' + a + '이고 \nb는 ' + b + '다';
// let str2 = `a는 ${a}이고
// b는 ${b}다`;
// console.log(str1);
// console.log(str2);

true, false; // 불리언값(boolean)

undefined; // undefined
// let a;
// console.log(a);
let a = null;

null; // null

// 게시판
// 글 제목, 글 내용, 작성자, 좋아요개수, 댓글갯ㅅ

let board = {
  name: '가나다',
  content: '이거는 글 입니다',
  writer: '둘리',
  likeCount: 120,
  commentsCount: 3,
};

// console.log("좋아요 개수 : ",board.likeCount);

{
} // 객체(object)

// 조건문 (if)

let compare = 10;

// compare 10보다 크면 OK 출력
// compare 10보다 작으면 NO 출력

// if (compare > 10) {
//   console.log('OK');
// } else if(compare === 10) {
//   console.log('10');
// } else {
//   console.log('NO');
// }

// 반복문 (for)

// let sum = 0;
// for(let i=0; i<=10; i=i+1) {
//   sum = sum + i;
// }
// console.log('sum : ', sum);

// 반복문 (while)
// let i=0;
// let sum = 0;
// while(i<10) {
//   i = i + 1;
//   sum = i + sum;
// }
// console.log('sum : ', sum);

// 배열
// 0  1  2  3  4
let arr = [11, 22, 33, 44, 55, 66, 77, 1, 2, 3, 4, 12];
console.log('arr : ', arr);
console.log('세번째 값 : ', arr[4]);

let smallSum = 0;
let largeSum = 0;
for (let i = 0; i < arr.length; i = i + 1) {
  if (arr[i] < 40) {
    smallSum = smallSum + arr[i];
  } else {
    largeSum = largeSum + arr[i];
  }
}
console.log('sum : ', smallSum);
console.log('sum : ', largeSum);
