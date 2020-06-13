// File:    2-2-7.cpp
// Author:  csh
// Date:    2020/06/02
// ===================


template <typename T>
class List{
    private:
        int cur_len;            // 数组当前长度
        T *nodelist;            // 数组
    public:
        T remove(int ith){
            assert((cur_len != 0) && (ith > 0) && (ith <= cur_len));    // 必须存在一个可删除元素
            T tmp = nodelist[ith-1];
            for(int i = ith-1; i < cur_len-1; i++){
                // 向前移动
                nodelist[i] = nodelist[i+1];
            }
            cur_len--;
            return tmp;
        }
};
