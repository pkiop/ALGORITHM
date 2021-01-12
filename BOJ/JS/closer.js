function func() {
  let x = 13;
  function y() {
    console.log(x);
  }
  return y;
}

const fc = func();
fc();