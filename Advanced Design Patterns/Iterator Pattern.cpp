#include <iostream>
#include <vector>
using namespace std;

/*
====================================================
WITHOUT ITERATOR
====================================================

Problem:

Suppose a Playlist stores songs
inside a vector.

Every client directly accesses
the vector.

Code:

class Playlist {

public:

    vector<string> songs;

};

int main() {

    Playlist playlist;

    playlist.songs.push_back("Song A");
    playlist.songs.push_back("Song B");
    playlist.songs.push_back("Song C");

    for(int i = 0; i < playlist.songs.size(); i++) {

        cout << playlist.songs[i] << endl;

    }

}

Problems:

- Client knows Playlist uses vector.
- If Playlist changes to linked list,
  client code must change.
- Internal implementation is exposed.

====================================================
ITERATOR PATTERN
====================================================

Solution:

Provide an Iterator.

The client only asks:

hasNext()

next()

It never accesses the collection directly.

*/

// Iterator
class PlaylistIterator {

private:

    vector<string>& songs;

    int index = 0;

public:

    PlaylistIterator(vector<string>& songs)
        : songs(songs) {}

    bool hasNext() {

        return index < songs.size();

    }

    string next() {

        return songs[index++];

    }

};

// Collection
class Playlist {

private:

    vector<string> songs;

public:

    void addSong(string song) {

        songs.push_back(song);

    }

    PlaylistIterator getIterator() {

        return PlaylistIterator(songs);

    }

};

int main() {

    Playlist playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");

    PlaylistIterator iterator =
        playlist.getIterator();

    while(iterator.hasNext()) {

        cout << iterator.next() << endl;

    }

}

/*

Output:

Song A
Song B
Song C

Notice:

The client never accesses

vector<string>

directly.

It only communicates with the Iterator.

If Playlist later changes from

vector

to

linked list

the client code remains unchanged.

*/