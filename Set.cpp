#include <vector>
#include <string>

class set
{
private:
    // Kiểm tra xem 1 phần tử có nằm trong vector hay k
    static bool is_in(int n, std::vector<int> &vec)
    {
        for (auto e : vec)
        {
            if (e == n)
            {
                return true;
            }
        }
        return false;
    }
    // Tương tự cái trên nhưng mà kiểu char
    static bool is_in(char n, std::vector<char> &vec)
    {
        for (auto e : vec)
        {
            if (e == n)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Cả ba hàm "create" đều biến đổi tham số vào thành 1 set
    // Hàm này là vector<int>
    static void create(std::vector<int> &int_vec)
    {
        // Tạo 1 biến att để lưu những phần tử
        std::vector<int> att;
        for (int i = 0; i < int_vec.size(); i++)
        {
            // Nếu trong att chưa có phần tử này thì add vào
            if (is_in(int_vec[i], att) == false)
            {
                att.push_back(int_vec[i]);
            }
        }
        // Xoá toàn bộ vector vào, thay thế nó bằng các phần tử trong att
        // att chưa các phần tử chỉ lặp lại 1 lần (E.g: set)
        int_vec.clear();
        for (int i : att)
        {
            int_vec.push_back(i);
        }
    }
    // Hàm này là vector<char>
    static void create(std::vector<char> &char_vec)
    {
        std::vector<char> att;
        for (int i = 0; i < char_vec.size(); i++)
        {
            if (is_in(char_vec[i], att) == false)
            {
                att.push_back(char_vec[i]);
            }
        }
        char_vec.clear();
        for (char i : att)
        {
            char_vec.push_back(i);
        }
    }
    // Hàm này là string
    static void create(std::string &str)
    {
        std::vector<char> att(str.begin(), str.end());
        create(att);
        str = std::string(att.begin(), att.end());
    }
};
