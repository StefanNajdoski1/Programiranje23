#include <iostream>
#include <cstring>
using namespace std;

// Pecatenje od momentalnata sostojba na tablata Iks Nula
void pTabla(char tabla[])
{
cout << "          |          |          " << endl;
cout << "          |          |          " << endl;
cout << "     " << tabla[0] << "    |     " << tabla[1] << "    |     " << tabla[2] << "     " << endl;
cout << "          |          |          " << endl;
cout << "----------|----------|----------" << endl;
cout << "          |          |          " << endl;
cout << "          |          |          " << endl;
cout << "     " << tabla[3] << "    |     " << tabla[4] << "    |     " << tabla[5] << "     " << endl;
cout << "          |          |          " << endl;
cout << "----------|----------|----------" << endl;
cout << "          |          |          " << endl;
cout << "          |          |          " << endl;
cout << "     " << tabla[6] << "    |     " << tabla[7] << "    |     " << tabla[8] << "     " << endl;
cout << "          |          |          " << endl;


} 

// Proverka dali ima pobednik na tablata
char checkWinner(char tabla[])
{
   // Proverka na redovite
    for (int i = 0; i < 9; i += 3)
    {
        if (tabla[i] == tabla[i + 1] && tabla[i] == tabla[i + 2])
        {
            return tabla[i];
        }
    }
    
   // Proverka na  kolinite
    for (int i = 0; i < 3; i++)
    {
        if (tabla[i] == tabla[i + 3] && tabla[i] == tabla[i + 6])
        {
            return tabla[i];
        }
    }
    
    // Proverete gi dijagonalite
    if (tabla[0] == tabla[4] && tabla[0] == tabla[8])
    {
        return tabla[0];
    }
    if (tabla[2] == tabla[4] && tabla[2] == tabla[6])
    {
        return tabla[2];
    }
    return ' ';
}
int main()
{
    char tabla[9];
    memset(tabla, ' ', sizeof(tabla));
    
    // Inicijalizirajte ja tablata so prazni mesta
    int igrac = 1;
    char simbol = 'X';
    int sDvizenje = 0;
    cout << "Dobredojdovte vo igrata Iks Nula!" << endl;
    
    // Jamka za igra
    while (sDvizenje < 9)
    {
        pTabla(tabla);
        cout << "Player " << igrac << ", vnesete broj pomegu 1 i 9: ";
        int pozicija;
        cin >> pozicija;
        
    // Proverete dali vlezot e validen
        if (pozicija < 1 || pozicija > 9)
        {
            cout << "Nevazecki vlez. Vnesete broj pomegu 1 i 9." << endl;
            continue;
        }
        if (tabla[pozicija - 1] != ' ')
        {
            cout << "Taa pozicija e veke zemena. Ve molime izberete druga." << endl;
            continue;
        }
        
    // Se azurira tablata i se  proveruva dali ima pobednik
        tabla[pozicija - 1] = simbol;
        char pobednik = provPobednik(tabla);
        if (pobednik != ' ')
        {
            pTabla(tabla);
            cout << "Igracot " << igrac << " pobedi!" << endl;
            break;
        }
        
    // Prefrli igrac i simbol
        igrac = 3 - igrac;
        simbol = (simbol == 'X') ? 'O' : 'X';
        sDvizenje++;
    }
    
    if (sDvizenje == 9)
    {
        pTabla(tabla);
        cout << "Nereseno!";
    }
}