#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vemaybay
{
private:
    string tenchuyen;
    string ngaybay;
    double giave;

public:
    Vemaybay() {}
    ~Vemaybay() {}

    void Nhap()
    {
        cout << "Nhap ten chuyen: ";
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
        cin.ignore();
    }

    void Xuat()
    {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    double getGiaVe()
    {
        return giave;
    }
};


class Nguoi
{
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi() {}
    ~Nguoi() {}

    void Nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
    }

    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};


class Hanhkhach : public Nguoi
{
private:
    vector<Vemaybay> ve;
    int soluong;

public:
    Hanhkhach() : soluong(0) {}
    ~Hanhkhach() {}

    void Nhap()
    {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        cin.ignore();
        ve.resize(soluong);
        for (int i = 0; i < soluong; i++)
        {
            cout << "Nhap thong tin ve thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    void Xuat()
    {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; i++)
        {
            cout << "Thong tin ve thu " << i + 1 << ":" << endl;
            ve[i].Xuat();
        }
    }

    double tongTien()
    {
        double sum = 0;
        for (int i = 0; i < soluong; i++)
        {
            sum += ve[i].getGiaVe();
        }
        return sum;
    }
};


// bool cmpHanhKhach(const Hanhkhach &a, const Hanhkhach &b)
// {
//     return a.tongTien() > b.tongTien();
// }

int main()
{
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    cin.ignore();

    vector<Hanhkhach> danhSach(n);

 
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
        danhSach[i].Nhap();
    }

 
    cout << "Thong tin hanh khach va tong tien:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Hanh khach thu " << i + 1 << ":" << endl;
        danhSach[i].Xuat();
        cout << "Tong tien: " << danhSach[i].tongTien() << endl;
    }


    // sort(danhSach.begin(), danhSach.end(), cmpHanhKhach);

    
    cout << "Danh sach hanh khach da sap xep:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Hanh khach thu " << i + 1 << ":" << endl;
        danhSach[i].Xuat();
        cout << "Tong tien: " << danhSach[i].tongTien() << endl;
    }

    return 0;
}


