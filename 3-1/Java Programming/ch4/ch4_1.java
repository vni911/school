package ch4_pt;

class Song {
	String title;
	
	public Song(String title) {
		this.title = title;
	}
	
	public String getTitle() {
		return title;
	}
}
	
public class ch4_1{		
public static void main(String[] args) {
	Song mySong = new Song("Nessun Dorma");
	Song yourSong = new Song("공주는 잠 못 이루고");
	System.out.println("내 노래는 " + mySong.getTitle());
	System.out.println("네 노래는 " + yourSong.getTitle());
	}
}