<h1>List of music management programs</h1>

<h3>Implementation Functions</h3>
<h4>1. Real-time TOP10 Music</h4>
<h5>Implement top10 Music through SavedList using an array. Because the order of the 1st to 10th places needs to be clear, SavedList was used and the memory of the Musics entering the list is fixed by a total of 10 pieces, so SavedList using an array instead of LinkedList was chosen to be implemented. The data addition method first checks whether the topmusic class member variable SavedList is filled with 10 music. If the music is filled, start with a small number of plays and compare them to the music you want to enter. If the new music has a large number of plays, remove the smallest number of plays and add the new music to the SortedlList
</h5>
<h4>2. Music Database</h4> 
<h5>Store music data using Single LinkedList. Single LinkedList was used to input and store sound data. Since the volume of data on the sound source is not initially predictable, the user chose to reduce memory use by using LinkedList instead of a list using an array. In addition, the reason for using SingleLinkedList instead of DoubleLinkedList is that DoubleLinkedList uses more memory than SingleLinkedList, but it can be deleted quickly when data is deleted. However, the Music Application used SingleLinkedList, which is advantageous in memory usage, assuming that it will not often be deleted once a sound source is registered. In addition, two Primary_Key are set up to connect to Singer Database, one that matches a singer's unique Primary_Key and, when searching for the singer's Primary_Key, is printed out a song sung by that singer, so that it is not necessary to use memory by declaring a list in SingerType separately.
</h5>
<h4>3. Singer Database</h4>
<h5>Saving singer data using Single LinkedList. Single LinkedList was used to enter and store singer data. Since the singer's data is not initially predictable, it was chosen to reduce memory use by using LinkedList instead of a list using an array. In addition, the reason for using SingleLinkedList instead of DoubleLinkedList is that DoubleLinkedList uses more memory than SingleLinkedList, but it can be deleted quickly when data is deleted. However, using SingleLinkedList which is advantageous in memory usage because it is assumed that there will not be many cases when a singer is registered in Music Application.
</h5>
<h4>4. PlayList Database</h4>
<h5>Implement PlayList using Queue. For NodeType, obtain it as MusicType and link it to Real-Time TOPIx 1 implementation. Real-time TOP10 is affected by the number of plays, and users can try to add directly to the real-time top10 but playTime, a member of the MusicType of the music, is increased once when executing Play ALL Music or Play one music function of the PlayList. In addition, if the number of plays is increased once in the function, it is required to check whether the automatically played music can be uploaded to the real-time top10 so that real-time top10 can be modified to match the playtime without any input from the user.
</h5>
<h4>5. Simplify the running screen</h4>
<h5>The key implementation functions such as Song data, real-time top10, singer data, and playlist data are conveniently added or modified. In the first selection, we first selected which data to modify or add to the above four databases, and then select each of the following functions in detail:
</h5>
<h3>Remaining assignment</h3>
<h4>1. Applying the GUI</h4>
<h5>Fabricate GUI of Music App using Qt creator. It makes it easier for users to use the black execution screen within the current c++ with a slightly more visual In addition, the application class will be modified and supplemented accordingly to provide more convenient access to each function.
</h5>
<h4>2. Real-time top10 features are specified and enhanced</h4>
<h5>By using various data such as genre, singer, etc., functions that are composed only of playtime are implemented in various ways, finally implementing various kinds of top10 functions that are available to the user.
</h5>
