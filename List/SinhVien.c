typedef struct{
    char MSSV[10];
    char Ho_Ten[50];
    float DiemLT,DiemTH1,DiemTH2;
}SinhVien;
typedef SinhVien ElementType;
typedef struct{
    ElementType A[40];
    int n;
}DanhSach;
