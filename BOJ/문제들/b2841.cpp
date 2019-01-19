#include <iostream>
#include <stack>
using namespace std;
int main(void) {
       int n, m;
       cin >> n >> m;
       stack<int> a, b, c, d, e, f;
       a.push(0);
       b.push(0);
       c.push(0);
       d.push(0);
       e.push(0);
       f.push(0);
       int cnt = 0;
       for (int i = 0; i < n; ++i) {
               int temp1, temp2;
               cin >> temp1 >> temp2;
               if (temp1 == 1) {
                      if (a.top() < temp2) {
                              a.push(temp2);
                              cnt++;
                      }
                      else if (a.top() == temp2) {
                              //do nothing
                      }
                      else {
                              while (a.top() != 0) {
                                     if (a.top() > temp2) {
                                            a.pop();
                                            cnt++;
                                     }
                                     else {
                                            break;
                                     }
                              }
                              if (a.top() == temp2) {
                                     //do nothing
                              }
                              else {
                                     a.push(temp2);
                                            cnt++;
                              }
                      }
               }
               if (temp1 == 2) {
                      if (b.top() < temp2) {
                              b.push(temp2);
                              cnt++;
                      }
                      else if (b.top() == temp2) {
                              //do nothing
                      }
                      else {
                              while (b.top() != 0) {
                                     if (b.top() > temp2) {
                                            b.pop();
                                            cnt++;
                                     }
                                     else {
                                            break;
                                     }
                              }
                              if (b.top() == temp2) {
                                     //do nothing
                              }
                              else {
                                     b.push(temp2);
                                     cnt++;
                              }
                      }
               }
               if (temp1 == 3) {
                      if (c.top() < temp2) {
                              c.push(temp2);
                              cnt++;
                      }
                      else if (c.top() == temp2) {
                              //do nothing
                      }
                      else {
                              while (c.top() != 0) {
                                     if (c.top() > temp2) {
                                            c.pop();
                                            cnt++;
                                     }
                                     else {
                                            break;
                                     }
                              }
                              if (c.top() == temp2) {
                                     //do nothing
                              }
                              else {
                                     c.push(temp2);
                                     cnt++;
                              }
                      }
               }
               if (temp1 == 4) {
                      if (d.top() < temp2) {
                              d.push(temp2);
                              cnt++;
                      }
                      else if (d.top() == temp2) {
                              //do nothing
                      }
                      else {
                              while (d.top() != 0) {
                                     if (d.top() > temp2) {
                                            d.pop();
                                            cnt++;
                                     }
                                     else {
                                            break;
                                     }
                              }
                              if (d.top() == temp2) {
                                     //do nothing
                              }
                              else {
                                     d.push(temp2);
                                     cnt++;
                              }
                      }
               }
               if (temp1 == 5) {
                      if (e.top() < temp2) {
                              e.push(temp2);
                              cnt++;
                      }
                      else if (e.top() == temp2) {
                              //do nothing
                      }
                      else {
                              while (e.top() != 0) {
                                     if (e.top() > temp2) {
                                            e.pop();
                                            cnt++;
                                     }
                                     else {
                                            break;
                                     }
                              }
                              if (e.top() == temp2) {
                                     //do nothing
                              }
                              else {
                                     e.push(temp2);
                                     cnt++;
                              }
                      }
               }
               if (temp1 == 6) {
                      if (f.top() < temp2) {
                              f.push(temp2);
                              cnt++;
                      }
                      else if (f.top() == temp2) {
                              //do nothing
                      }
                      else {
                              while (f.top() != 0) {
                                     if (f.top() > temp2) {
                                            f.pop();
                                            cnt++;
                                     }
                                     else {
                                            break;
                                     }
                              }
                              if (f.top() == temp2) {
                                     //do nothing
                              }
                              else {
                                     f.push(temp2);
                                     cnt++;
                              }
                      }
               }
       }
       cout << cnt << endl;
       return 0;
}