package ui;

import code.ElevatorLogic;
import code.RequestGenerator;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.binding.BooleanBinding;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;


public class Main extends Application {

    @Override
    public void start(Stage mainStage) throws Exception {

        mainStage.getIcons().add(new Image(new FileInputStream("src" + File.separator +
                "img" + File.separator + "elv_icon.jpg")));

        mainStage.setTitle("Elevators Simulation");

        GridPane rootNode = new GridPane();
        rootNode.setId("pane1");
        rootNode.setPadding(new Insets(15));
        rootNode.setHgap(5);
        rootNode.setVgap(5);
        rootNode.setAlignment(Pos.CENTER);

        // add button
        Button beginning = new Button("WELCOME");
        beginning.setId("begin_btn");

        GridPane.setHalignment(beginning, HPos.CENTER);
        beginning.setTranslateX(27);
        beginning.setTranslateY(125);

        //add .gif
        Image image = new Image(new FileInputStream("src" + File.separator +
                "img" + File.separator + "elv.gif"));
        ImageView imageView = new ImageView(image);
        imageView.setX(25);
        imageView.setY(25);
        imageView.setFitHeight(450);
        imageView.setFitWidth(400);
        imageView.setPreserveRatio(true);


        Group root = new Group(imageView, beginning);
        rootNode.getChildren().add(root);
        Scene mainScene = new Scene(rootNode, 450, 400);
        mainScene.getStylesheets().addAll(this.getClass().getResource("style.css").toExternalForm());

        mainStage.setScene(mainScene);
        mainStage.show();

        beginning.setOnAction(e -> {
            // create 2nd scene
            addSecondScene(mainStage);
        });
    }

    public void addSecondScene(Stage mainStage) {
        GridPane rootNode2 = new GridPane();
        rootNode2.setId("pane2");
        rootNode2.setPadding(new Insets(15));
        rootNode2.setHgap(5);
        rootNode2.setVgap(5);
        rootNode2.setAlignment(Pos.CENTER);

        Scene scene2 = new Scene(rootNode2, 450, 400);
        scene2.getStylesheets().addAll(this.getClass().getResource("style.css").toExternalForm());

        //  3 input fields
        rootNode2.add(new Label("Number of elevators:"), 0, 0);
        TextField val1 = new TextField();
        val1.setPromptText("Enter integer, i > 0");
        val1.setStyle("-fx-prompt-text-fill: derive(-fx-control-inner-background, -30%);");

        val1.setTextFormatter(new TextFormatter<>(change ->
                (change.getControlNewText().matches("([1-9][0-9]*)?")) ? change : null));
        rootNode2.add(val1, 1, 0);

        rootNode2.add(new Label("Amount of floors:"), 0, 1);
        TextField val2 = new TextField();
        val2.setPromptText("Enter integer, i > 0");
        val2.setStyle("-fx-prompt-text-fill: derive(-fx-control-inner-background, -30%);");
        val2.setTextFormatter(new TextFormatter<>(change ->
                (change.getControlNewText().matches("([1-9][0-9]*)?")) ? change : null));
        rootNode2.add(val2, 1, 1);

        rootNode2.add(new Label("Available space in elevator:"), 0, 2);
        TextField val3 = new TextField();
        val3.setPromptText("Enter integer, i > 0");
        val3.setStyle("-fx-prompt-text-fill: derive(-fx-control-inner-background, -30%);");
        val3.setTextFormatter(new TextFormatter<>(change ->
                (change.getControlNewText().matches("([1-9][0-9]*)?")) ? change : null));
        rootNode2.add(val3, 1, 2);

        // add button (start elevators)
        Button start = new Button("START");
        // if any of 3 vals is empty, can't start app
        start.disableProperty().bind(checkInputData(val1, val2, val3));
        rootNode2.add(start, 1, 3);
        start.setId("start_btn");
        GridPane.setHalignment(start, HPos.LEFT);

        mainStage.setScene(scene2);

        // 3rd SCENE
        start.setOnAction(e2 -> {
            // create 3rd scene
            addThirdScene(mainStage, val1, val2, val3);
        });
    }

    public void addThirdScene(Stage mainStage, TextField val1, TextField val2, TextField val3) {
        Button exit = new Button("EXIT");
        GridPane.setRowIndex(exit, 10);
        GridPane.setColumnIndex(exit, 0);

        exit.setId("exit_btn");

        GridPane rootNode3 = new GridPane();
        rootNode3.setId("pane3");
        rootNode3.setPadding(new Insets(5));
        rootNode3.setAlignment(Pos.CENTER);

        rootNode3.getChildren().add(exit);

        Scene scene3 = new Scene(rootNode3, 450, 400);
        scene3.getStylesheets().addAll(this.getClass().getResource("style.css").toExternalForm());

        mainStage.setScene(scene3);

        exit.setOnAction(f -> {
            Platform.exit();
            System.exit(0);
        });

        BorderPane borderPane = new BorderPane();
        rootNode3.getChildren().add(borderPane);
        HBox hbox = new HBox();
        rootNode3.getChildren().add(hbox);
        hbox.setAlignment(Pos.TOP_CENTER);
        hbox.setPadding(new Insets(15, 12, 15, 12));
        hbox.setSpacing(10);
        hbox.setStyle("-fx-background-color : #2d9bf3;");
        borderPane.setTop(hbox);

        Text elvAmountTxt = new Text();
        elvAmountTxt.setText("ELEVATORS AMOUNT: " + val1.getText() + " ||");
        elvAmountTxt.setStyle("-fx-text-inner-color : #f2f1f3;");
        Font font = Font.font("Courier New", FontWeight.BOLD, 14);
        elvAmountTxt.setFont(font);
        hbox.getChildren().add(elvAmountTxt);
        ///////////////
        Text flrAmountTxt = new Text();
        flrAmountTxt.setId("floors_am_txt");
        flrAmountTxt.setText("FLOORS IN BUILDING: " + val2.getText());
//        flrAmountTxt.setStyle("-fx-text-fill : #f2f1f3;");
//        Font font2 = Font.font("Courier New", FontWeight.BOLD, 14);
//        flrAmountTxt.setFont(font2);
        hbox.getChildren().add(flrAmountTxt);
        //////////////

        TextArea ta = new TextArea();
        ta.setId("console_output");

        Console console = new Console(ta);  /////////////////// THINK !!!!!!!

        PrintStream ps = new PrintStream(console, true);

        System.setOut(ps);
        System.setErr(ps);

        borderPane.setCenter(ta);
        // start program
        startThreads(val1, val2, val3);
    }

    public BooleanBinding checkInputData(TextField val1, TextField val2, TextField val3) {
        return new BooleanBinding() {
            {
                super.bind(val1.textProperty(),
                        val2.textProperty(),
                        val3.textProperty());
            }

            @Override
            protected boolean computeValue() {
                return (val1.getText().isEmpty()
                        || val2.getText().isEmpty()
                        || val3.getText().isEmpty());
            }
        };
    }

    public void startThreads(TextField val1, TextField val2, TextField val3) {
        int elevatorsNumber = Integer.parseInt(val1.getText());
        int floorsAmount = Integer.parseInt(val2.getText());
        int space = Integer.parseInt(val3.getText());

        ElevatorLogic el = new ElevatorLogic(floorsAmount, space, elevatorsNumber);
        RequestGenerator rg = new RequestGenerator(floorsAmount, el);
        // thread for people requests
        Thread requestsThread = new Thread(rg);
        requestsThread.start();
        // thread for elevators
        Thread elevatorsThread = new Thread(el);
        elevatorsThread.start();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
