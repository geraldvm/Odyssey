#include "file.h"

File::File()
{

}


void File::muestra_contenido_de()
{

    QString h = QDir::homePath();//.tostdstring;
    h.append("/Music/Odyssey");

    std::string f = h.toStdString();
    std::cout<< f << std::endl;
    DIR *dir;
    dirent *ent;
    if (DIR* dir = opendir("/home/fio/Music/Odyssey/Temppp"))
    {
        while (dirent* ent = readdir(dir) ){
            std::cout << ent->d_name << '\n';
        }
      closedir (dir);
    }

}
