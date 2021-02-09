#include <iostream>
#include <list>
using namespace std;


struct music_disc
{
    char name[20];
    char author[20];
    int duration;
    int price;
};

void disc_write(list<music_disc> discs)
{
    FILE* file;
    if ((file = fopen("disc_collection.bin", "wb")) == NULL)
    {
        perror("Unable to open file");
        exit(0);
    }
    for (auto &i : discs)
    {
        fwrite(&((i).name), sizeof(char[20]), 1, file);
        fwrite(&((i).author), sizeof(char[20]), 1, file);
        fwrite(&((i).duration), sizeof(int), 1, file);
        fwrite(&((i).price), sizeof(int), 1, file);
    }
    
    fclose(file);
}

void disc_print(int n)
{
    FILE* file;
    if ((file = fopen("disc_collection.bin", "rb")) == NULL)
    {
        perror("Unable to open file");
        exit(0);
    }
    char name[20];
    char author[20];
    int duration;
    int price;
    for (int k = 1; k <=n; k++)
    {
        cout << endl;
        cout << "Disc number " << k << ":" << endl;
        fread(&name, sizeof(char[20]), 1, file);
        cout << "Disc name: " << name << endl;
        fread(&author, sizeof(char[20]), 1, file);
        cout << "Disc author: " << author << endl;
        fread(&duration, sizeof(int), 1, file);
        cout << "Disc duration: " << duration << endl;
        fread(&price, sizeof(int), 1, file);
        cout << "Disc price: " << price << endl;
    }
    fclose(file);
}

list<music_disc> disc_remove(list<music_disc> discs, int duration)
{
    int i = 0;
    for (auto& disc : discs)
    {
        if (disc.duration == duration)
        {
            list<music_disc>::iterator pos = discs.begin();
            advance(pos, i);
            discs.erase(pos);
            return discs;
        }
        i++;
    }
    return discs;
}

list<music_disc> disc_insert(list<music_disc> discs, int  n, music_disc value)
{
    list<music_disc>::iterator pos = discs.begin();
    advance(pos, n);
    discs.insert(pos, value);
    return discs;
}

int main()
{
    list<music_disc> discs;
    cout << "How much discs to add to the collection? ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        music_disc disc;
        cout << "Disc name: ";
        cin >> disc.name;
        cout << "Disc author: ";
        cin >> disc.author;
        cout << "Disc duration: ";
        cin >> disc.duration;
        cout << "Disc price: ";
        cin >> disc.price;
        discs.push_back(disc);
    }
    disc_write(discs);
    disc_print(discs.size());
    int duration;
    cout << "With what duration disc to delete? ";
    cin >> duration;
    discs = disc_remove(discs, duration);
    int pos;
    cout << "After what position to insert discs? ";
    cin >> pos;
    cout << "How much discs to insert? ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        music_disc disc;
        cout << "Disc name: ";
        cin >> disc.name;
        cout << "Disc author: ";
        cin >> disc.author;
        cout << "Disc duration: ";
        cin >> disc.duration;
        cout << "Disc price: ";
        cin >> disc.price;
        discs = disc_insert(discs, pos + i, disc);
    }
    disc_write(discs);
    disc_print(discs.size());
    return 0;
}
