#include <iostream>
#include <cstdint> 
#include <fstream>
#include <vector>
#include <string>
#include <string_view>
#include <iomanip>

using namespace std;

enum RoomType : uint8_t
{
    Bedroom = 0,    ///< Спальня
    Kitchen = 1,    ///< Кухня
    Bathroom = 2,   ///< Ванная
    Childrens = 3,  ///< Детсткая
    Living = 4,     ///< Гостинная
    EndRooms = 5
};

enum BuildingType : uint8_t
{
    Garage = 0,     ///< Гараж
    Barn = 1,       ///< Сарай
    BathHouse = 2,  ///< Баня
    House = 3,      ///< Дом
    EndBuilds = 4
};

string_view ToString(RoomType room) noexcept
{
    switch (room)
    {
        case RoomType::Bedroom:   return "Спальня";
        case RoomType::Kitchen:   return "Кухня";
        case RoomType::Bathroom:  return "Ванная";
        case RoomType::Childrens: return "Детсткая";
        case RoomType::Living:    return "Гостинная";
        default:                  { break; }
    }
    return "Неизвестная комната";
}

string_view ToString(BuildingType build) noexcept
{
    switch (build)
    {
        case BuildingType::Garage:     return "Гараж";
        case BuildingType::Barn:       return "Сарай";
        case BuildingType::BathHouse:  return "Баня";
        case BuildingType::House:      return "Дом";
        default:                       { break; }
    }
    return "Неизвестное здание";
}

RoomType GetRoomType()
{
    cout << "Введите тип комнаты: " << endl;
    int value;
    for (int i = static_cast<int>(RoomType::Bedroom); i < static_cast<int>(RoomType::EndRooms); ++i) 
    {
        auto elem = static_cast<RoomType>(i);
        cout << "\t" << i << " - " << ToString(elem) << endl;
    }
    cin >> value;
    cout << value << '\n';          
    return static_cast<RoomType>(value);
}

BuildingType GetBuildingType()
{
    cout << "Введите тип здания: " << endl;
    int value;
    for (int i = static_cast<int>(BuildingType::Garage); i < static_cast<int>(BuildingType::EndBuilds); ++i) 
    {
        auto elem = static_cast<BuildingType>(i);
        cout << "\t" << i << " - " << ToString(elem) << endl;
    }
    cin >> value;
    cout << value << '\n';          
    return static_cast<BuildingType>(value);
}

struct Room
{
    double area;
    RoomType roomName;

    Room() 
        : area(0)
        , roomName(RoomType::Bedroom)
    {};
};

void GetCurrentRoom(Room& currentRoom)
{
    currentRoom.roomName = GetRoomType();
    cout << "Площадь комнаты: ";
    cin >> currentRoom.area;
    cout << currentRoom.area << '\n';   
}

struct Floor
{
    int floatNum;
    int ceilingHeight;
    vector<Room> allRooms;

    Floor()
        : floatNum(0)
        , ceilingHeight(0)
        , allRooms({})
    {};
};

void GetCurrentFloor(Floor& currentFloor)
{
    cout << "Этаж: " << currentFloor.floatNum << " - высота потолка: ";
    cin >> currentFloor.ceilingHeight;
    cout << currentFloor.ceilingHeight << '\n';    (вместо пустого endl)

    int roomsCount;
    do
    {
        cout << "Количество комнат на этаже (2-4): ";
        cin >> roomsCount;
        cout << roomsCount << '\n';                
        if ((roomsCount < 2) || (roomsCount > 4))
        {
            cout << "Ошибка! Допустимо от 2 до 4 комнат." << endl;
        }
    }
    while ((roomsCount < 2) || (roomsCount > 4));

    for (int j = 0; j < roomsCount; j++)
    {
        Room currentRoom;
        GetCurrentRoom(currentRoom);
        currentFloor.allRooms.push_back(currentRoom);
    }
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~" << endl;
}

struct Building
{
    BuildingType buildType;
    vector<Floor> floorsVec;
    double buildArea;
    bool presenceChimney;

    Building()
        : buildType(BuildingType::House)
        , floorsVec({})
        , buildArea(0)
        , presenceChimney(false)
    {}; 
};

void GetCurrentBuilding(Building& build)
{
    build.buildType = GetBuildingType();

    cout << "Площадь, занимаемая зданием: ";
    cin >> build.buildArea;
    cout << build.buildArea << '\n';   

    switch (build.buildType)
    {
        case BuildingType::BathHouse:
        {
            cout << "Есть ли печь с трубой? (1 - да, 0 - нет): ";
            cin >> build.presenceChimney;
            cout << build.presenceChimney << '\n';   
            break;
        }

        case BuildingType::House:
        {
            int floorsVecCount;
            do
            {
                cout << "Введите количество этажей (1-3): ";
                cin >> floorsVecCount;
                cout << floorsVecCount << '\n';         
                if ((floorsVecCount < 1) || (floorsVecCount > 3))
                {
                    cout << "Ошибка! Этажей должно быть от 1 до 3." << endl;
                }
            } while ((floorsVecCount < 1) || (floorsVecCount > 3));

            for (int i = 0; i < floorsVecCount; i++)
            {
                Floor currentFloor;
                currentFloor.floatNum = i+1;
                GetCurrentFloor(currentFloor);
                build.floorsVec.push_back(currentFloor);
            }
            cout << "Есть ли печь с трубой? (1 - да, 0 - нет): ";
            cin >> build.presenceChimney;
            cout << build.presenceChimney << '\n';  
            break;
        }
        case BuildingType::Garage:
        case BuildingType::Barn:
        default:
        {
            break;
        }
    }
    cout << endl;
    cout << "********************" << endl;
}

struct Plot
{
    int plotNum;
    vector<Building> buildVec;

    Plot()
        : plotNum(0)
        , buildVec({})
    {};
};

void GetCurrentPlot(Plot& currentPlot)
{
    cout << "Номер участка: ";
    cin >> currentPlot.plotNum;
    cout << currentPlot.plotNum << '\n';   

    int buildingCount;
    cout << "Количество построек на участке: ";
    cin >> buildingCount;
    cout << buildingCount << '\n';         

    for (int i = 0; i < buildingCount; i++)
    {
        Building currentBuild;
        GetCurrentBuilding(currentBuild);
        currentPlot.buildVec.push_back(currentBuild);
    }
}

struct Village
{
    double fullArea;
    vector<Plot> plotVec;

    Village()
        : fullArea(0)
        , plotVec({})
    {};
};

void PrintRoom(const Room& r, int indentLevel)
{
    std::string indent(indentLevel, '\t');
    cout << indent << "Комната: " << ToString(r.roomName)
         << " (площадь " << r.area << " кв.м)" << endl;
}

void PrintFloor(const Floor& currentFloor, int indentLevel)
{
    std::string indent(indentLevel, '\t');
    cout << indent << "Этаж " << currentFloor.floatNum
         << ", высота потолка " << currentFloor.ceilingHeight << " см" << endl;
    if (currentFloor.allRooms.empty())
    {
        cout << indent << "  (нет комнат)" << endl;
    }
    else
    {
        for (const auto& room : currentFloor.allRooms)
        {
            PrintRoom(room, indentLevel + 1);
        }
    }
}

void PrintBuilding(const Building& build, int indentLevel)
{
    std::string indent(indentLevel, '\t');
    cout << indent << "Здание: " << ToString(build.buildType)
         << " (площадь застройки " << build.buildArea << " кв.м)" << endl;

    if (build.buildType == BuildingType::House)
    {
        cout << indent << "  Количество этажей: " << build.floorsVec.size() << endl;
        for (const auto& floor : build.floorsVec)
        {
            PrintFloor(floor, indentLevel + 2);
        }
    }

    if ((build.buildType == BuildingType::House) || (build.buildType == BuildingType::BathHouse))
    {
        cout << indent << "  Печь с трубой: " << (build.presenceChimney ? "да" : "нет") << endl;
    }
}

void PrintPlot(const Plot& p, int indentLevel)
{
    std::string indent(indentLevel, '\t');
    cout << indent << "Участок №" << p.plotNum << endl;
    if (p.buildVec.empty())
    {
        cout << indent << "  (нет построек)" << endl;
    }
    else
    {
        for (const auto& build : p.buildVec)
        {
            PrintBuilding(build, indentLevel + 1);
        }
    }
}

void PrintVillage(const Village& currentVillage)
{
    cout << "========== ИНФОРМАЦИЯ О ПОСЁЛКЕ ==========" << endl;
    cout << "Общая площадь территории: " << currentVillage.fullArea << " кв.м" << endl;
    cout << "Количество участков: " << currentVillage.plotVec.size() << endl;

    double builtArea = 0.0;
    for (const auto& plot : currentVillage.plotVec)
    {
        for (const auto& build : plot.buildVec)
        {
            builtArea += build.buildArea;
        }
    }
    double percent = (currentVillage.fullArea > 0) ? (builtArea / currentVillage.fullArea * 100.0) : 0.0;
    cout << "Суммарная площадь застройки: " << builtArea
         << " кв.м (" << fixed << setprecision(1) << percent << "%)" << endl;
         
    cout << endl;
    cout << "---------- ДЕТАЛИЗАЦИЯ УЧАСТКОВ ----------" << endl;
    for (const auto& plot : currentVillage.plotVec)
    {
        PrintPlot(plot, 0);
        cout << endl;  
    }
}

int main()
{
    Village currentVillage;

    cout << "Общая площадь посёлка: ";
    cin >> currentVillage.fullArea;
    cout << currentVillage.fullArea << '\n';   

    int plotCount;
    cout << "Количество участков: ";
    cin >> plotCount;
    cout << plotCount << '\n';                 

    for (int i = 0; i < plotCount; i++)
    {
        Plot currentPlot;
        GetCurrentPlot(currentPlot);
        currentVillage.plotVec.push_back(currentPlot);
        cout << endl;
    }

    PrintVillage(currentVillage);

    return 0;
}
