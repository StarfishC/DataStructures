// File:    6-1-18.cpp
// Author:  csh
// Date:    2020/12/31
// ===================


// 第一个待比较的顶点
x = 0;
for(y = 2; y < n; y++){         // 依次比较n-1个顶点
    if(matrix[x][y] > 0)        // 如果存在x至y的边则x非漏，将y与y+1比较
        x = y;                  // 否则，y非漏，讲x和y+1比较
}
// n-1次比较后，x代表唯一可能是漏的顶点
bool find = true;
// 判断x是否是漏
for(y = 0; y < n; y++){
    if(y != x && matrix[y][x] <= 0 || matrix[x][y] > 0){
        find = false;
        break;
    }
}
// 如果x是漏，则输出
if(find)
    cout << "Find: " << x << endl;
else
    cout << "No point statisfying requirement. " << endl;
