//22110670 김정운

import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class HW3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("파일 이름? ");
        String filename = scan.nextLine();

        try {
            FileReader fileReader = new FileReader(filename);
            int[] preorder = fileReader.getPreorder();
            int[] inorder = fileReader.getInorder();

            LinkedBinaryTree<Integer> tree = new LinkedBinaryTree<>();
            tree.root = makeTree(preorder, inorder);

            System.out.print("Postorder:[ ");
            for (Position<Integer> pos : tree.postorder()){
                System.out.print(pos.getElement() + " ");
            }
            System.out.println("]");

            System.out.println("왼쪽과 오른쪽의 차가 1 이하? " +  String.valueOf(tree.boolheight()).toUpperCase());
        } catch (FileNotFoundException e){
            System.out.println("파일을 찾을 수 없습니다");
        }
    }

    private static TreeNode<Integer> makeTree(int[] preorder, int[] inorder) {
        return PreInTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private static TreeNode<Integer> PreInTree(int[] preorder, int preLeft, int preRight, int[] inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) return null;

        int rootVal = preorder[preLeft];
        TreeNode<Integer> root = new TreeNode<>(rootVal);

        int rootIndex = -1;
        for (int i = inLeft; i <= inRight; i++) {
            if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
            }
        }

        int nodeLeft = rootIndex - inLeft;
        
        root.setLeft(PreInTree(preorder, preLeft + 1, preLeft + nodeLeft, inorder, inLeft, rootIndex - 1));
        root.setRight(PreInTree(preorder, preLeft + nodeLeft + 1, preRight, inorder, rootIndex + 1, inRight));

        return root;
    }
}

class FileReader {
    private int[] preorder;
    private int[] inorder;

    public FileReader(String filename) throws FileNotFoundException {
        Scanner fileScanner = new Scanner(new File(filename));

        int count = fileScanner.nextInt();
    
        fileScanner.nextLine();

        preorder = readArray(fileScanner, count);
        inorder = readArray(fileScanner, count);

        fileScanner.close();
    }

    private int[] readArray(Scanner scanner, int count) {
            String line = scanner.nextLine().trim();
            String[] tokens = line.split(" ");
            int[] array = new int[count];
        for (int i = 0; i < count; i++) {
            array[i] = Integer.parseInt(tokens[i]);
        }
        return array;
    }

    public int[] getPreorder() { return preorder;}
    public int[] getInorder() { return inorder;}
}

interface Position<E> {
    E getElement() throws IllegalStateException;
}

class TreeNode <E> implements Position<E> {
    private E element;
    private TreeNode<E> left, right;
    public TreeNode(E element){this.element = element;}
    public TreeNode(E element, TreeNode<E> left, TreeNode<E> right)
    {this.element = element; this.left = left; this.right = right;}

    public E getElement() throws IllegalStateException{return element;}
    public void setLeft(TreeNode<E> left) { this.left = left; }
    public void setRight(TreeNode<E> right) { this.right = right; }
    public TreeNode<E> getLeft(){return left;}
    public TreeNode<E> getRight(){return right;}
}

class LinkedBinaryTree<E>{
    protected TreeNode<E> root = null;

    public Position<E> root(){return root;}

    public Position<E> left(Position<E> p){
        TreeNode<E> node = validate(p);
        return node.getLeft();
    }

    public Position<E> right(Position<E> p){
        TreeNode<E> node = validate(p);
        return node.getRight();
    }

    protected TreeNode<E> validate(Position<E> p) {
        if(!(p instanceof TreeNode))
            throw new IllegalStateException("Invalid position");
        return (TreeNode<E>)p;
    }

    public Iterable<Position<E>> postorder(){
        List<Position<E>> array = new ArrayList<Position<E>>();
        postorderSubtree(root(), array);
        return array;
    }

    private void postorderSubtree(Position<E> p, List<Position<E>> array){
        if (p!=null){
            TreeNode<E> node = validate(p);
            postorderSubtree(left(p), array);
            postorderSubtree(right(p), array);
            array.add(p);
        }
    }
    
    public boolean boolheight(){
        return height(root) != -1;
    }
    private int height(TreeNode<E> node){
        if (node == null)
            return 0;
        if(height(node.getLeft()) - height(node.getRight()) > 1 || height(node.getRight()) - height(node.getLeft()) > 1 )
            return -1;
        if(height(node.getLeft()) == -1)
            return -1;
        if(height(node.getRight()) == -1)
            return -1;
        return Math.max(height(node.getLeft()), height(node.getRight())) + 1;
    }
}