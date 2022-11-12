/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MidtermAnswers;

/**
 *
 * @author fattanezarrinkalam
 */
import java.util.ArrayList;

public class LibraryTest {
    public static void main(String[] args) {
        Library library = new Library();
        library.setName("XYZ State University Library");
        Book book1 = new Book();
        book1.setTitle("Java The Complete Reference");
        book1.addAuthors(new Author("Herbert", "Schildt"));
        library.addBooks(book1);
        Book book2 = new Book();
        book2.setTitle("More JAVA 17");
        book2.addAuthors(new Author("Kishori", "Sharan"));
        book2.addAuthors(new Author("Peter", "Spath"));
        library.addBooks(book2);
        Book book3 = new Book();
        book3.setTitle("C Programming Language");
        book3.addAuthors(new Author("Brian", "kernighan"));
        book3.addAuthors(new Author("Dennis", "Ritchie"));
        library.addBooks(book3);

        ArrayList<Book> searchedBooks = library.searchBooks("JAVA");
        for (int i = 0; i < searchedBooks.size(); i++) {
            System.out.println(searchedBooks.get(i).getTitle());
        }
    }
    
}
