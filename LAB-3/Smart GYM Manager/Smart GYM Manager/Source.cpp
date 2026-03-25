#include <iostream>
#include <string>
#include <fstream> // Dosya okuma/yazma için

using namespace std;

// 1. Üye Yapısı (Struct)
struct Member {
    int id;
    string name;
    double weight;
    double height;
};

// --- FONKSİYON PROTOTİPLERİ ---
void addNewMember(Member*& list, int& size);
void removeMember(Member*& list, int& size);
void listMembers(Member* list, int size);
void saveToDisk(Member* list, int size);
void loadFromDisk(Member*& list, int& size);

int main() {
    Member* gymList = nullptr; // Dinamik dizi başlangıcı
    int size = 0;
    int choice;

    // Program açılır açılmaz eski verileri yükle
    loadFromDisk(gymList, size);

    do {
        cout << "\n--- OSMANGAZI SMART GYM ---" << endl;
        cout << "1. Yeni Uye Ekle" << endl;
        cout << "2. Uye Sil (ID ile)" << endl;
        cout << "3. Tum Uyeleri Listele" << endl;
        cout << "4. Verileri Kaydet" << endl;
        cout << "5. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
        case 1: addNewMember(gymList, size); break;
        case 2: removeMember(gymList, size); break;
        case 3: listMembers(gymList, size); break;
        case 4: saveToDisk(gymList, size); break;
        case 5: cout << "Sistem kapatiliyor..." << endl; break;
        default: cout << "Gecersiz secim!" << endl;
        }
    } while (choice != 5);

    // Belleği temizlemeyi unutma!
    delete[] gymList;

    return 0;
}

// --- FONKSİYONLARIN İÇİNİ DOLDURMA VAKTİ ---

void addNewMember(Member*& list, int& size) {

	Member* temp = new Member[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = list[i];
	}

	cout << "İsim: ";
	cin >> temp[size].name;
	cout << "Kilo: ";
	cin >> temp[size].weight;
	cout << "Boy: ";
	cin >> temp[size].height;
	cout << "4 haneli ID belirleyiniz: ";
    cin >> temp[size].id;

    bool isUnique;
    do {
        isUnique = true; 

        if (temp[size].id < 1000 || temp[size].id > 9999) {
            cout << "Lütfen 4 haneli bir ID giriniz: ";
            cin >> temp[size].id;
            isUnique = false;
            continue;
        }

        for (int i = 0; i < size; i++) {
            if (temp[size].id == temp[i].id) {
                cout << "Bu ID zaten mevcut. Lütfen farklı bir ID giriniz: ";
                cin >> temp[size].id;
                isUnique = false;
                break;
            }
        }
    } while (!isUnique);

    delete[] list; // Eski belleği temizle
    list = temp; // Yeni listeyi ata
	size++; // Boyutu artır
}

void removeMember(Member*& list, int& size) {

	int idToRemove;

	cout << "Silinecek Uyenin ID'sini giriniz: ";
	cin >> idToRemove;

    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if (list[i].id == idToRemove) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "HBu ID'ye sahip bir uye bulunamadi!" << endl;
        return;
    }

	Member* temp = new Member[size - 1];
    
   int index = 0;
    for (int i = 0; i < size; i++) {
        if (list[i].id != idToRemove) {
            temp[index++] = list[i];
        }
    }
    delete[] list; // Eski belleği temizle
	list = temp;  // Yeni liste
	size--; // Boyutu azalt

}

void listMembers(Member* list, int size) {
    for (int i = 0; i < size; i++) {

        double bmi = list[i].weight / (list[i].height * list[i].height);

        cout << "ID: " << list[i].id

            << ", Isim: " << list[i].name

            << ", Kilo: " << list[i].weight

            << ", BMI: " << bmi << endl;
    }
}

void saveToDisk(Member* list, int size) {
    // TODO: 'ofstream' kullanarak verileri "gym_data.txt" içine yaz.
}

void loadFromDisk(Member*& list, int& size) {
    // TODO: 'ifstream' kullanarak dosyayı aç, satır satır oku 
    // ve her okuduğun satır için diziyi büyüterek içeri al.
}