# Markdown Summary
## 1. header
#(1~6) = h1, h2 ... h6

## 2. Emphasis(*, **, ~~)
    *italic*   
    **bold**  
    ~~cancelline~~    
example)   
*italic*   
**bold**  
~~cancelline~~      

## 3. BlockQuote (>)
can include other markdown elements   
ex) 
> like this

## 4. List (number, *, +, -)
ex)
* lev.1
    + lev.2
        - lev.3
            - lev.4

## 5. Code Block (tap, ```<pre><code></code></pre>```, ```)
* using TAP or 4space

* using```<pre><code></code></pre>```

* using(```) 
    + this method can be Syntax highlighting if you declare language
    
    ex) 
    ```java
    public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
    ```

### 5.1 Code (``)
ex) `code`

## 6. Horizon (`<hr/>`)
make horizon line

ex)
<hr/>

## 7. Link (`[title](link)`)
    
ex)

    [google](http://google.com)
[Google](http://google.com)

http://example.com/

## 8. Image 
`![Alt text](/path/to/img.jpg)` or `<img>`

## 9. Table
    | Syntax | Description |
    | ----------- | ----------- |
    | Header | Title |
    | Paragraph | Text |
    
- alignment
```
left align `:---`
middle align `:---:`
right align `---:`
| :--- | :---: |
```

| Syntax | Description |
| :--- | :----: |
| Header | Title |
| Paragraph | Text |

## 10. Footnote
    [^name]

    [^name] : explane.

Here's a sentence with a footnote. [^123] 
[^123]: This is the footnote.

## 11. Heading ID
    [name](#headname)
    <a href="#heading-ids">Heading IDs</a>

ex)   
[go to 1. header](#1-header-)  
[go to 2. emphasis](#2-emphasis--)  
<a href="#heading-id">Heading ID</a>

## 12. Check Box
    - [x] A
    - [ ] B
    - [ ] C

- [x] A  
- [ ] B

## 13. Emoji
[Emoji lists](https://gist.github.com/rxaviers/7360908)  

## Etc
* Subscript  
    H~2~O

* Superscript  
    x^2^