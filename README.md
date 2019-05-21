# vector
## self made vector

### First task

#### Realizuotos funkcijos:

1. `push_back` funkcija, kuri prideda nurodytą elementą į vektoriaus galą.

```c++
    void push_back(T i) {
        if(vsize + 1 > maxsize)
            resize(vsize + 10);
        array[vsize] = i;
        vsize++;
    }
 ```
 
2. `pop_back` funkcija, kuri panaikina paskutinį vektoriaus elementą.
 
 ```c++
    void pop_back () {
        if(vsize != 0)
            vsize--;
    }
 ```
 
 3. `clear` funkcija išvalo visą vektorių ir jo dydį prilyginą nuliui.
 
  ```c++
    void clear() { vsize = 0; delete[] array; array = new T[maxsize]; }
    }
 ```
 
 4. `empty` funkcija patikrina ar vektorius yra tusčias ir gražina bool tipo reikšmę.
 
   ```c++
    bool empty() { return vsize == 0; }
    }
   ```
   
 5. `Operator []` leidžia pasiekti kurį nori vektoriaus elementą, nurodant to elemento indeksą.
 
 ```c++
     T& operator[](size_t i) { 
        if (i < 0 || i >= vsize) throw std::out_of_range("Element is out of range");
        return array[i]; }
  ```
 
 #### Self made ir `std::vector` funkcijų veikimo palyginimas:
 
 ```c++
    vector<int> v1(10); //self made vector
    std::vector<int> v2(10); //std::vector

    //Size Funkcija
    cout << "SIZE: ";
    cout << v1.size() << " ";
    cout << v2.size() << endl;

    //Capacity funkcija
    cout << "CAPACITY: ";
    cout << v1.capacity() << " ";
    cout << v2.capacity() << endl;

    //Push_back funkcija
    v1.push_back(14);
    v2.push_back(14);

    //[] operator
    cout << "10 ELEMENT: ";
    cout << v1[10] << " ";
    cout << v2[10] << endl;

    //Pop_back funkcija
    v1.pop_back();
    v2.pop_back();

    //Size Funkcija
    cout << "SIZE: ";
    cout << v1.size() << " ";
    cout << v2.size() << endl;

    //Clear funkcija
    v1.clear();
    v2.clear();

    //Size Funkcija
    cout << "SIZE: ";
    cout << v1.size() << " ";
    cout << v2.size() << endl;

    //Empty funkcija
    cout << "EMPTY(bool): ";
    cout << v1.empty() << " ";
    cout << v2.empty() << endl;
 ```
    
  #### Rezultatai: 
  ```
SIZE: 10 10
CAPACITY: 10 10
10 ELEMENT: 14 14
SIZE: 10 10
SIZE: 0 0
EMPTY(bool): 1 1
```
  Taigi, galima pastebėti, jog mano savadarbio vektoriaus ir `std::vector` funkcijų rezultatai yra vienodi.
  
 ### Second task
 
 #### Self made vector ir `std::vector` spartos analizė, atliekant `push_back`:
 
 1. unsigned int sz = 10000
 ```
 Self made vector uztruko 0.000571359sec
 std::vector uztruko 0.000253472sec
```
2. unsigned int sz = 100000
```
Self made vector uztruko 0.0034432sec
std::vector uztruko 0.00257519sec
```
3. unsigned int sz = 1000000
```
Self made vector uztruko 0.0441019sec
std::vector uztruko 0.0191643sec
```
4. unsigned int sz = 10000000
```
Self made vector uztruko 0.186319sec
std::vector uztruko 0.176335sec
```
5. unsigned int sz = 100000000
```
Self made vector uztruko 1.72743sec
std::vector uztruko 1.55253sec
```
Šis bandymas aiškiai parodo, jog mano kurtas vektorius funkciją `push_back` vykdo ilgiau nei `std::vector`.

### Third task

#### Atminties perskirstymas

Tiek mano self made vectoriuje, tiek `std::vector`, užpildant 100000000 elementų, įvyko po 27 atminties perskirstymus.
  
