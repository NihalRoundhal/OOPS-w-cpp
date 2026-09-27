#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media {
protected:
    string title;
    string fileType;

public:
    Media(string t, string f) {
        title = t;
        fileType = f;
    }

    virtual void play() {
        cout << "Playing media..." << endl;
    }

    virtual void pause() {
        cout << "Media paused." << endl;
    }

    virtual void stop() {
        cout << "Media stopped." << endl;
    }

    virtual void showDetails() const {
        cout << "Title: " << title << endl;
        cout << "Type: " << fileType << endl;
    }

    virtual ~Media() {}
};

class Audio : public Media {
private:
    string artist;

public:
    Audio(string t, string a)
        : Media(t, "Audio") {
        artist = a;
    }

    void play() override {
        cout << "Playing audio: " << title << endl;
    }

    void pause() override {
        cout << "Audio paused." << endl;
    }

    void stop() override {
        cout << "Audio stopped." << endl;
    }

    void showDetails() const override {
        cout << "Audio: " << title << endl;
        cout << "Artist: " << artist << endl;
    }
};

class Video : public Media {
private:
    string quality;

public:
    Video(string t, string q)
        : Media(t, "Video") {
        quality = q;
    }

    void play() override {
        cout << "Playing video: " << title << endl;
    }

    void pause() override {
        cout << "Video paused." << endl;
    }

    void stop() override {
        cout << "Video stopped." << endl;
    }

    void showDetails() const override {
        cout << "Video: " << title << endl;
        cout << "Quality: " << quality << endl;
    }
};

class Image : public Media {
private:
    string resolution;

public:
    Image(string t, string r)
        : Media(t, "Image") {
        resolution = r;
    }

    void play() override {
        cout << "Displaying image: " << title << endl;
    }

    void pause() override {
        cout << "Image viewing paused." << endl;
    }

    void stop() override {
        cout << "Image viewing stopped." << endl;
    }

    void showDetails() const override {
        cout << "Image: " << title << endl;
        cout << "Resolution: " << resolution << endl;
    }
};

int main() {
    vector<Media*> mediaList;

    mediaList.push_back(new Audio("Shape of You", "Ed Sheeran"));
    mediaList.push_back(new Video("Avengers Endgame", "4K"));
    mediaList.push_back(new Image("Sunset Landscape", "2560x1440"));

    cout << "===== MEDIA PLAYER =====" << endl;

    for (auto media : mediaList) {
        cout << "\n------------------------" << endl;
        media->showDetails();
        media->play();
        media->pause();
        media->stop();
    }

    for (auto media : mediaList) {
        delete media;
    }

    return 0;
}
