
#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

// kiem tra la phan tu cuoi chua
bool check_arr(int i, int size_arr){
    if( i == size_arr - 1){
        return true;
    }else{
        return false;
    }
}

// tinh tong n1 so le 2 chu so lon nhat 
int sum_11(int n1){
    int arr[45];
    int i = 0;
    int sum = 0;
    for (int j = 99; j >= 11; j -= 2){
        arr[i] = j;
        i++;
    }
    for (int i = 0; i < n1; i++){
        sum += arr[i];
    }
    return sum;
}

// kiem tra so nguyen to 
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// so nguyen to gan n nhat 
int num_prime(int n) {
    int num = n + 1;
    while (is_prime(num) == false) {
        num++;
    }
    return num;
}

// kiem tra HP la so nguyen to
bool check(int HP){
    if (HP == 0 or HP == 1){
        return false;
    }
    else {
        for (int i = 2; i < HP; i++){
            if (HP % i == 0){
                return false;
            }
        }
        return true;
    }
}

// tim so fibonacci gan n nhat 
int number_fibonacci(int n) {
    int fib1 = 0, fib2 = 1, fib3 = 1;
    while (fib3 < n) {
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }
    return fib2;
}

// xu ly nam ma so 1
void code_1(string file_mush_ghost, int index, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue){
    
    ifstream file;
        file.open(file_mush_ghost);
        int n2;
        file >> n2; 
        // doc du lieu hang 2 
        string line;
        getline(file,line); 
        int arr[n2];
        int x;
        int countelm1 = -1;
        if (getline(file,line)){
            stringstream ss(line);
            string token;
            while(getline(ss, token,',')){
                countelm1 += 1;
                x = countelm1;
                arr[x] = stoi(token);
            }
        }
    file.close();

    int maxi = 0;
    int mini = 0;
    int max = arr[0];
    int min = arr[0];
    //tim vi tri lon nhat xu ly ma so 1
    for (int i = 0; i < n2; i++){
        if (arr[i] >= max){
            max = arr[i];
            maxi = i;
        }
    }
    
    // tim vi tri nho nhat xu ly ma so 1
    for (int i = 0; i < n2; i++){
        if (arr[i] <= min){
            min = arr[i];
            mini = i;
        }
    }
    // cap nhat lai HP
    HP = HP - (maxi + mini);
    rescue = -1;
}

// tra ve phan tu lon nhat cua mang
void max_arr(int arr[], int n, int& gt_max, int& vt_max){
    int max = arr[0];
    for (int i = 0; i < n; i++){
        if(arr[i] >= max){
            max = arr[i]; 
            vt_max = i;
        }
    }
    gt_max = max;
}

// tra ve phan tu nho nhat cua mang
void min_arr(int arr[], int n, int& gt_min, int& vt_min){
    int min = arr[0];
    for (int i = 0 ; i < n; i++){
        if(arr[i] <= min){
            min = arr[i];
            vt_min = i; 
        }
    }
    gt_min = min;
}

// kiem tra mang tang giam hinh tui xu ly ma so 2
void check_arr_mush(int arr[], int n, int& mtx, int& mti){
    int gt_max,gt_min,vt_max,vt_min;
    max_arr(arr,n,gt_max,vt_max);
    min_arr(arr,n,gt_min,vt_min);

    int check_tang = arr[0] - 2;
    int check_giam = gt_max;
    if(vt_min == 0 || vt_min == n-1){
        for (int i = 0; i < vt_max ; i++){
            if (arr[i] == arr[i+1] || arr[i] == gt_max){
                return;
            }
            if(check_tang < arr[i]){
                check_tang = arr[i];
            }else{
                return;
            }
        }
        for (int i = vt_max + 1; i < n; i++){
            if (arr[i] == arr[i+1] || arr[i] == gt_max){
                return;
            }
            if(check_giam > arr[i]){
                check_giam = arr[i];
            }else{
                return;
            }
        }
        mtx = gt_max;
        mti = vt_max;
        return;
    }else{
        return;
    }
}

// xu ly nam ma so 2
void code_2(string file_mush_ghost, int index, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue){
    
    ifstream file;
    file.open(file_mush_ghost);
        int n2;
        file >> n2; 
        
        // doc du lieu hang 2 
        string line;
        getline(file,line); // doc dong 1 
        int arr[n2];
        int x;
        int countelm1 = -1;
        if (getline(file,line)){
            stringstream ss(line);
            string token;
            while(getline(ss, token,',')){
                countelm1 += 1;
                x = countelm1;
                arr[x] = stoi(token);
            }
        }
    file.close();

    int mtx = -2;
    int mti = -3;
    int arr_mush[n2];
    for (int i = 0; i < n2; i++){
        arr_mush[i] = arr[i];
    }
    check_arr_mush(arr_mush,n2,mtx,mti);
    // cout << mtx << " " << mti << endl;
    HP = HP - (mtx + mti);
}

//xu ly nam ma so 3
void code_3(string file_mush_ghost, int index, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue){
    
    ifstream file;
    file.open(file_mush_ghost);
        int n2;
        file >> n2; 
        // doc du lieu hang 2 
        string line;
        getline(file,line);
        int arr[n2];
        int x;
        int countelm1 = -1;
        if (getline(file,line)){
            stringstream ss(line);
            string token;
            while(getline(ss, token,',')){
                countelm1 += 1;
                x = countelm1;
                arr[x] = stoi(token);
            }
        }
    file.close();

    int arr_mush[n2];
    for(int i = 0; i < n2; i++){
        arr_mush[i] = arr[i];
    }
    //bien doi dieu kien 1
    for (int i = 0; i < n2; i++){
        if (arr_mush[i] < 0){
            arr_mush[i] = -arr_mush[i];
        }
    }
    // bien doi dieu kien 2
    for (int i = 0; i < n2; i++){
        arr_mush[i] = (17*arr_mush[i]+9)%257;
    }

    int maxi = 0;
    int mini = 0;
    int max = arr_mush[0];
    int min = arr_mush[0];
    //phan tu lon nhat
    for (int i = 0; i < n2; i++){
        if (arr_mush[i] >= max){
            max = arr_mush[i];
        }
    }
    // vi tri dau tien xuat hien
    for (int i = 0; i < n2; i++){
        if (arr_mush[i] == max){
            maxi = i;
            break;
        }
    }
    //tim gia tri nho nhat
    for (int i = 0; i < n2; i++){
        if (arr_mush[i] <= min){
            min = arr_mush[i];
        }
    }
    //tim vi tri xuat hien dau tien phan tu nho nhat
    for (int i = 0; i < n2; i++){
        if (arr_mush[i] == min){
            mini = i;
            break;
        }
    }
    // cout << mini << "  " << maxi << endl;
    // xu ly HP
    HP = HP - (maxi + mini);
}

// sap xep mang tang dan
void sortArray(int arr[], int n) {
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

// xu ly nam ma so 4
void code_4(string file_mush_ghost, int index, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue){
    
    ifstream file;
    file.open(file_mush_ghost);
        int n2;
        file >> n2; 
        // doc du lieu hang 2 
        string line;
        getline(file,line);
        int arr[n2];
        int x;
        int countelm1 = -1;
        if (getline(file,line)){
            stringstream ss(line);
            string token;
            while(getline(ss, token,',')){
                countelm1 += 1;
                x = countelm1;
                arr[x] = stoi(token);
            }
        }
    file.close();

    // xu ly mang nhu nam ma loai 3
    int arr_temp[n2];
    for(int i = 0; i < n2; i++){
        arr_temp[i] = arr[i];
    }

    // bien doi dieu kien 1
    for (int i = 0; i < n2; i++){
        if (arr_temp[i] < 0){
            arr_temp[i] = -arr_temp[i];
        }
    }

    //bien doi dieu kien 2
    for(int i=0;i<n2;i++){
        arr_temp[i] = (17*arr_temp[i] + 9) % 257;
    }
    // tim ra so lon thu 2 trong 3 so dau tien 
    int max2, max2_index;
    if(n2 < 2){
        max2 = -5;
        max2_index = -7;
    }
    else if(n2 == 2){
        if (arr_temp[0] != arr_temp[1]){
            if (arr_temp[0] > arr_temp[1]){
                max2 = arr_temp[1];
                max2_index = 1;
            }else{
                max2 = arr_temp[0];
                max2_index = 0;
            }
        }else{
            max2 = arr_temp[0];
            max2_index = 0;
        }
    }
    else if (arr_temp[0] == arr_temp[1] && arr_temp[0] == arr_temp[2]){
        max2 = -5;
        max2_index = -7;
    }
    else if(arr_temp[0] == arr_temp[1] && arr_temp[0] != arr_temp[2]){
        if (arr_temp[0] > arr_temp[2]){
            max2 = arr_temp[0];
            max2_index = 0;
        }else{
            max2 = arr_temp[2];
            max2_index = 2; 
        }
    }
    else if(arr_temp[1] == arr_temp[2] && arr_temp[1] != arr_temp[0]){
        if(arr_temp[1] > arr_temp[0]){
            max2 = arr_temp[1];
            max2_index = 1;
        }else{
            max2 = arr_temp[0];
            max2_index = 0;
        }
    }
    else if (arr_temp[2] == arr_temp[0] && arr_temp[0] != arr_temp[1]){
        if(arr_temp[2] > arr_temp[1]){
            max2 = arr_temp[2];
            max2_index = 2;
        }else{
            max2 = arr_temp[1];
            max2_index = 1;
        }
    }
    else{
        if(arr_temp[0] > arr_temp[1] && arr_temp[0] < arr_temp[2] || arr_temp[0] < arr_temp[1] && arr_temp[0] > arr_temp[2]){
            max2 = arr_temp[0];
            max2_index = 0;
        }
        else if (arr_temp[1] > arr_temp[0] && arr_temp[1] < arr_temp[2] || arr_temp[1] < arr_temp[0] && arr_temp[1] > arr_temp[2]){
            max2 = arr_temp[1];
            max2_index = 1;
        }
        else if(arr_temp[2] > arr_temp[0] && arr_temp[2] < arr_temp[1] || arr_temp[2] < arr_temp[0] && arr_temp[2] > arr_temp[1]){
            max2 = arr_temp[2];
            max2_index = 2;
        }
    }
    // cout << max2 << " " << max2_index << endl;
    // cap nhat HP
    HP = HP - (max2 + max2_index);
}

// ma su kien 13
void event_code_13(string file_mush_ghost,int index, int event_code, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int maxHP){
    //tao mang luu su kien gap nam ma loai may
    int arr_code[1000];
    int len_arr_code = 0;
    int j = 0;
    while(event_code > 13){
        arr_code[j] = event_code % 10;
        event_code /= 10;
        j++;
        len_arr_code++;
    }

    // xu ly viec gap tung loai nam ma
    for (int i = len_arr_code - 1; i >= 0; i--){
        if(HP <= 0 && phoenixdown <= 0){
            break;
        }
        if(arr_code[i]  == 1){
            code_1(file_mush_ghost,index,HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }else if(arr_code[i] == 2){
            code_2(file_mush_ghost,index,HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(arr_code[i] == 3){
            code_3(file_mush_ghost,index,HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if (arr_code[i] == 4){
            code_4(file_mush_ghost,index,HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }
        if (HP > maxHP){
            HP = maxHP;
        }
        if(HP < 0 && phoenixdown < 1){
            rescue = 0;
            return;
        }
        if(HP < 0 && phoenixdown > 0){
            phoenixdown--;
            HP = maxHP;
        }
    }
    rescue = -1;
}

// ma su kien 19
void event_code_19(string file_aclepius_pack,int& meet,int index, int event_code, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int maxHP) {
    if(meet == 0){

        meet++;
        ifstream inFile(file_aclepius_pack);
        int r1, c1;
        inFile >> r1 >> c1;
        int data[r1][c1];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                inFile >> data[i][j];
            }
        }
        for (int i=0;i<r1;i++){
            int count = 0;
            for (int j=0;j<c1;j++){
                if( data[i][j] == 16 && remedy < 99){
                    remedy++;
                    count++;
                }
                else if (data[i][j] == 17 && maidenkiss < 99){
                    maidenkiss++;
                    count++;
                }
                else if(data[i][j] == 18 && phoenixdown < 99){
                    phoenixdown++;
                    count++;
                }
                if(count == 3){
                    break;
                }
            }
        }
        rescue = -1;
    }
    else{
        rescue = -1;
    }   
}

// ma su kien 0 toi 5
void event_code_do(int index, int event_code, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int maxHP){
    // ma su kien bang 0
    if(event_code == 0){
        rescue = 1;
    }
    // ma su kien tu 1 den 5
    else if (event_code >= 1 and event_code <= 5){
        int level0;
        float arr[5] = {1,1.5,4.5,7.5,9.5};
        int b = index % 10;
        level0 = index > 6?(b > 5?b : 5) : b;
        if (check(maxHP) == true || maxHP == 999){
            level++;
            rescue = -1;
        }
        else if ((level > level0 and level < 10) or (check(maxHP) == true)){
            level++;
            rescue = -1;
        }
        else if(level == level0 and level < 10){
            rescue = -1;
        }
        else if (level < level0){
            float baseDamage = (float)arr[event_code-1];
            float damage = baseDamage * level0 * 10;
            HP = HP - damage;
            if (HP <= 0 and phoenixdown < 1){
                rescue = 0;
            }
            else if (HP <= 0 and phoenixdown > 0){
                phoenixdown--;
                HP = maxHP;
                rescue = -1;
            }
        }
    }
    else if (event_code == 11){
        int s1;
        int n1;
        n1 = ((level + phoenixdown)%5 + 1) * 3;
        s1 = sum_11(n1);

        HP = HP + (s1 % 100);
        HP = num_prime(HP);
        
        if (HP > maxHP){
            HP = maxHP;
        }
        rescue = -1;
    }
    else if (event_code == 12){
        if (HP > 1){
            HP = number_fibonacci(HP);
            rescue = -1;
        }
        else if (HP == 1){
            rescue = -1;
        }
    }
    else if (event_code == 15 && remedy < 99){
        remedy++;
        rescue = -1;
    }
    else if (event_code == 16 && maidenkiss < 99){
        maidenkiss++;
        rescue = -1;
    }
    else if (event_code == 17 && phoenixdown < 99){
        phoenixdown++;
        rescue = -1;
    }
    else if (event_code == 99){
        if ((check(maxHP) == true && level >= 8) || (level == 10) || maxHP == 999){
            rescue = -1;
            level = 10;
        }
        else {
            rescue = 0;
        }
    }
}

//chuyen in hoa thanh in thuong 
void toLowercase(std::string& str) {
    for (char& c : str) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
}

// ham cap nhat lai HP dua tren ten mon do
void increaseHP(int& HP, string itemName,int maxHP) {
    
    if (itemName.find("Merlin") != string::npos || itemName.find("merlin") != string::npos) {
        HP += 3;
    } 
    
    else if (itemName.length() >= 6) {
        bool foundAllChars = true;
        toLowercase(itemName);
        string merlinChars = "merlin";
        for (int i = 0; i < merlinChars.length(); i++) {
            if (itemName.find(merlinChars[i]) == string::npos) {
                foundAllChars = false;
                break;
            }
        }
        if (foundAllChars) {
            HP += 2;
        }
    }
    
    if (HP > maxHP) {
        HP = maxHP;
    }
}

// ham xu ly ma su kien 18
void event_code_18(string file_merlin_pack,int& meet_merlin,int index, int event_code, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int maxHP) {
    if (meet_merlin == 0){
        
        ifstream inFile(file_merlin_pack);
        if (!inFile) {
            cout << "Khong the mo file " << file_merlin_pack << endl;
            return;
        }
        
        int n;
        inFile >> n;
        string itemName;
        for (int i = 0; i < n; i++) {
            inFile >> itemName;
            increaseHP(HP, itemName, maxHP);
        }
        inFile.close();

        meet_merlin++;
        rescue = -1;
    }else{
        rescue = -1;
        return;
    }
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    // ten cua 3 file 
    string file_aclepius_pack;
    string file_merlin_pack;
    string file_mush_ghost;

    int meet = 0; // xu kien so 19
    int meet_merlin = 0;
    rescue = -1; 

    ifstream file;
    file.open(file_input); 
        string line;
        long long arr1[5], arr2[1000];
        int x, countelm_arr1 = -1, countelm_arr2 = -1;
        int countelm1 = 0, countelm2 = 0;
        
        // đọc dòng đầu tiên  
        if (getline(file, line))
        { 
            stringstream ss(line);
            string token;
            while (getline(ss, token, ' ')) 
            { // phân tách các phần tử bằng dấu cách
                countelm1 += 1;
                countelm_arr1 += 1;
                x = countelm_arr1;
                arr1[x] = stoi(token);
            }     
        }

        if (getline(file, line))
        {  // đọc dòng thứ hai
            stringstream ss(line);
            string token;
            while (getline(ss, token, ' ')) 
            { // phân tách các phần tử bằng dấu cách
                countelm2 += 1;
                countelm_arr2 += 1;
                x = countelm_arr2;
                arr2[x] = stoi(token);
            }     
        }
    file.close();

    HP = arr1[0]; 
    level = arr1[1];
    remedy = arr1[2];
    maidenkiss = arr1[3];
    phoenixdown = arr1[4];
    int maxHP = HP;

    // neu HP = 999 -> chien thang
    // if (HP == 999){
    //     rescue = 1;
    //     display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    //     return;
    // }

    // mo file doc du lieu dong so 3
    ifstream inFile(file_input);
        if (!inFile.is_open()) {
            cout << "khong the mo file" << endl;
            return;
        }
        // doc du lieu dong so 3
        string line_3;
        int dem = 1;
        while (getline(inFile, line_3)) {
            if (dem == 3) {
                
                size_t pos1 = line_3.find(",");
                size_t pos2 = line_3.find(",", pos1 + 1);
                file_mush_ghost = line_3.substr(0, pos1);
                file_aclepius_pack = line_3.substr(pos1 + 1, pos2 - pos1 - 1);
                file_merlin_pack = line_3.substr(pos2 + 1);
                break;
            }
            dem++;
        }
    inFile.close();

    long long event_code;
    // neu dong 2 rong
    if( countelm2 == 0 ){
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        return;
    }

    // xu ky tung su kien
    for (int i = 0; i < countelm2; i++){
        
        event_code = arr2[i];
        
        // su kien 6 co the bien ty hon 
        if (arr2[i] == 6){
            int level0;
            int b = (i+1) % 10;
            level0 = (i+1) > 6?(b > 5?b : 5) : b;

            if (check(maxHP) == true || maxHP == 999){
                level += 2;
                if(level >= 10){
                    level = 10;
                }
                rescue = -1;
            }
            else if (level > level0 || check(maxHP) == true){
                level += 2;
                if(level >= 10){
                    level = 10;
                }
                rescue = -1;
            }
            else if (level == level0){
                rescue = -1;
            }
            else if(level < level0 && remedy > 0 ){
                remedy--;
                rescue = -1;
                if(check_arr(i, countelm2) == true){
                    rescue = 1;
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                    return;
                }
                //display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            }
            else if ((level < level0) && (remedy < 1)){
                // dung while de xu ly bien thanh ty hon
                int count = 3; // dem so luot ty hon 
                if (HP < 5){
                    HP = 1;
                    rescue = -1;
                    if(i == countelm2 - 1){
                        rescue = 1;
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                }
                else{
                    HP = HP / 5;
                    // cout << i << " " << countelm2 << endl;
                    if(i == (countelm2 - 1)){
                        rescue = 1;
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                }
                while (count != 0 && remedy < 1){

                    if(i == (countelm2 - 1)){
                        rescue = 1;
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }

                    i++;
                    if (arr2[i] == 6 or arr2[i] == 7) {
                        // cout << "chot 1" << endl;
                        goto start;
                    };

                    // vuot qua phan tu mang
                    if (i == countelm2){
                        if (rescue == -1){
                            rescue = 0;
                            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                            return;
                        }
                    }

                    event_code = arr2[i];
                    // gap su kien 19
                    if (arr2[i] == 19){
                        event_code_19(file_aclepius_pack,meet,(i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                        goto start;
                    }

                    // gap su kien 18
                    if(arr2[i] == 18){
                        event_code_18(file_merlin_pack,meet_merlin,(i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                        goto start;
                    }

                    //gap su kien 13
                    if (arr2[i] > 99){
                        event_code_13(file_mush_ghost,(i+1),arr2[i],HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                        goto start;
                    }

                    event_code_do((i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                    if (rescue == 1){
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    else if(rescue == 0){
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    start:
                        if (remedy > 0){
                            remedy--;
                            HP = HP*5;
                            if (HP >= maxHP){
                                HP = maxHP;
                            }
                            // cout << i << " " << countelm2 << endl;
                            if (i == (countelm2 - 1)){
                                if (rescue == -1){
                                    rescue = 1;
                                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                                    return;
                                }
                            }
                            goto check;
                        }

                        if (i == (countelm2 - 1)){
                            if (rescue == -1){
                                HP = HP*5;
                                if (HP >= maxHP){
                                    HP = maxHP;
                                }
                                rescue = 1;
                                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                                return;
                            }
                        }
                        // cout << "chot 2" << endl;
                        count--;
                    if (count == 0){
                        HP = HP*5;
                        if (HP >= maxHP){
                            HP = maxHP;
                        }
                        if (i == (countelm2 - 1)){
                            if (rescue == -1){
                                rescue = 1;
                                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                                return;
                            }
                        }
                        goto check;
                        break;
                    }
                    else if(i == countelm2 - 1){
                        rescue = 1;
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    else{
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                    }
                }
            }
            goto check;
        }

        // su kien co ma la 7 
        if (arr2[i] == 7){
            int level0;
            int b = (i+1) % 10;
            level0 = (i+1) > 6?(b > 5?b : 5) : b;

            if ((check(maxHP) == true || maxHP == 999)){
                level += 2;
                if(level >= 10){
                    level = 10;
                }
                rescue = -1;
            }
            else if (level > level0){
                level += 2;
                if(level >= 10){
                    level = 10;
                }
                rescue = -1;
            }
            else if (level == level0){
                rescue = -1;
            }
            else if (level < level0 && maidenkiss > 0){
                level = level;
                maidenkiss--;
                if(check_arr(i, countelm2) == true){
                    rescue = 1;
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                    return;
                }
            }
            else if (level < level0 && maidenkiss < 1){
                // bien thanh ech trong 3 luot ke tiep
                int count = 3;
                int before_level = level;
                level = 1;
                if(i == (countelm2 - 1)){
                    rescue = 1;
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                    return;
                }
                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);

                while (count != 0 && maidenkiss < 1){

                    if(i == (countelm2 - 1)){
                        rescue = 1;
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }

                    i++;
                    if (arr2[i] == 6 or arr2[i] == 7) {
                        // cout << "chot 1";
                        goto start_1;
                    };

                    // gap su kien 19
                    if (arr2[i] == 19){
                        event_code_19(file_aclepius_pack,meet,(i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                        goto start_1;
                    }

                    // gap su kien 18
                    if(arr2[i] == 18){
                        event_code_18(file_merlin_pack,meet_merlin,(i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                        goto start_1;
                    }

                    //gap su kien 13
                    if (arr2[i] > 99){
                        event_code_13(file_mush_ghost,(i+1),arr2[i],HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                        goto start_1;
                    }

                    event_code = arr2[i];

                    event_code_do((i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
                    if (rescue == 1){
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    else if(rescue == 0){
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
 
                    start_1:
                        if (maidenkiss > 0){
                            maidenkiss--;
                            level = before_level;
                            if (i == countelm2 - 1){
                                if (rescue == -1){
                                    rescue = 1;
                                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                                    return;
                                }
                            }
                            break;
                        }

                        if (i == countelm2 - 1){
                            if (rescue == -1){
                                rescue = 1;
                                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                                return;
                            }
                        }
                        // cout << "chot 2"<< endl;
                        count--;
                    
                    if (count == 0){
                        level = before_level;
                        if (i == countelm2 - 1){
                            if (rescue == -1){
                                rescue = 1;
                                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                                return;
                            }
                        }
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        break;
                    }
                    else if(i == countelm2 - 1){
                        rescue = 1;
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                        return;
                    }
                    else{
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                    }
                }
            }
            goto check;
        }

        // ma su kien 19
        if (arr2[i] == 19){
            event_code_19(file_aclepius_pack,meet,(i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
            goto check;
        }
        
        // ma su kien 13
        if(arr2[i] > 99){
            event_code_13(file_mush_ghost,(i+1),arr2[i],HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
            goto check;
        }

        // ma su kien 18
        if(arr2[i] == 18){
            event_code_18(file_merlin_pack,meet_merlin,(i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
            goto check;
        }
        
        // su kien tu 0 den 12
        event_code_do((i+1),event_code,HP,level,remedy,maidenkiss,phoenixdown,rescue,maxHP);
        // cout << "chot" << endl;
        check:
        if(HP <= 0 && phoenixdown > 0){
            phoenixdown--;
            HP = maxHP;
        }
        if (HP <= 0 && phoenixdown <= 0){
            rescue = 0;
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            return;
        }
        if (rescue == 1){
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            return;
        }
        else if (rescue == 0){
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            return;
        }
        else if(i == (countelm2 - 1) && rescue == -1){
            rescue = 1;
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            return;
        }
        else if(rescue == -1 && check_arr(i,countelm2) == true){
            rescue = 1;
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            return;
        }
        else{
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }
    }
}

