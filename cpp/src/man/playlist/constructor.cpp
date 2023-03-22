#include <iterator>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <shlobj.h>
#include "xml/rapidxml.hpp"
#include "man/settings.hpp"
#include "man/playlist.hpp"

vs::man::playlist::playlist(const vs::t::mptr& m, const std::string& xmlpath): player(m) {
    std::ifstream playlist(xmlpath);
    if (playlist.good()) {
        std::vector <char> xmlbuffer((std::istreambuf_iterator<char>(playlist)), std::istreambuf_iterator<char>());
        xmlbuffer.push_back('\0');

        rapidxml::xml_document<> xml;
        rapidxml::xml_node<>* root;

        xml.parse<0>(&xmlbuffer[0]);
        root = xml.first_node("Playlist");
        std::string mroot;
        CHAR windows_music_path[MAX_PATH];
        HRESULT result = SHGetFolderPath(NULL, CSIDL_MYMUSIC, NULL, SHGFP_TYPE_CURRENT, windows_music_path);

        if (result != S_OK) {
            mroot = root->first_attribute("mroot")->value();
            std::cout << "Failed to get Windows Music directory path, using XML path: " << mroot << std::endl;
        }
        else {
            mroot = std::string(windows_music_path) + std::string("\\");
            std::cout << "Using Windows Music directory path: " << mroot << std::endl;
        }

        for (rapidxml::xml_node<>* song = root->first_node("Song"); song; song = song->next_sibling()) {
            std::string fpath = mroot + song->first_attribute("file")->value();

            std::ifstream f(fpath);
            if (f.good()) {
                vs::music m(fpath, song->first_node("ControlPoint"));
                songlist.push_back(m);
            }
            else {
                std::cout << "Not found: " << fpath << std::endl;
                continue;
            }
        }

        if (songlist.size() == 0) {
            throw vs::except::playlist_empty;
        }
    }
    else {
        throw vs::except::playlist_file;
    }

    unsigned bufset = std::stoi(vs::man::settings::smap[vs::man::settings::ABUFSIZE]);
    bufsize = (songlist.size() <= bufset) ? (songlist.size()) : (bufset);
    for (unsigned i = 0; i < bufsize; ++i) songlist[i].initBuffer();
    playing->copyData(songlist[0]);
    current = 0;
}
