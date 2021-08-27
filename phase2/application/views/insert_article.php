<html>
<head>
    <title>admin insert</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <script src="../../ckeditor/ckeditor.js"></script>
    <link rel="stylesheet" href="../../../include/css/insert_article.css">
    <script>
        $(document).ready(function() {
            $(".butt").click(function () {
            var id = $(this).attr('id');
                jQuery.ajax({
                    type: "POST",
                    url: "../../../admin/delete",
                    data: {id: id},
                    success: function (result) {
                        $("#tr_" + id).remove();
                    }
                });
            });
        });
    </script>
    <script>
        $(document).ready(function() {
            $(".ChangePublish").change(function () {
                var id = $(this).attr('id');
                var showing = $(this).attr('data-num');

                jQuery.ajax({
                    type: "POST",
                    url: "../../../admin/showing",
                    data: {id:id , showing: showing},
                    success: function (result) {
                    }
                });
            });
        });
    </script>
    <script>CKEDITOR.replace( 'editor1' );</script>
</head>
<body>
<?php
    if (@$_SESSION['user_login']=='') {
        header("Location:http://localhost/admin"); /* Redirect browser */
        exit;
    }
?>
<?= form_open_multipart('admin/insert');?>
<?php
if (@$_SESSION['user_login']!='')
{

    echo '
<link href="https://fonts.googleapis.com/css?family=Oleo+Script:400,700" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Teko:400,700" rel="stylesheet">
<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet">

<section id="contact">
     <h1 style="text-align: center" class="section-header"><a href="http://localhost/admin" class="btn btn-danger">Logout</a></h1>
    <div class="section-content">
        <h1 class="section-header">Article Insert</h1>
    </div>
    <div class="contact-section">
        <div class="container">
            <form>
                <div class="col-md-6 form-line">
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-info">Title</span></h3>
                        <input type="text" class="form-control" id="title" name="title" placeholder=" Enter Title" required>
                    </div>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-info">Pre_Text</span></h3>
                        <textarea class="form-control" id="pretext" name="pretext" placeholder=" Enter pretext" required></textarea>
                    </div>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-info">Image</span></h3>
                        <input type="file" class="form-control" id="image" name="image" >
                        <br><br>
                    </div>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-info">Topic</span></h3>
                    <select style="
color: black" name="topic" id="topic" >
                            <option value="choose_topic" selected disabled>choose a topic</option>
                            <option value="athletic">athletic</option>
                            <option value="political">political</option>
                            <option value="cultural">cultural</option>
                            <option value="religious">religious</option>
                            <option value="historical">historical</option>
                            <option value="scientific">scientific</option>
                            <option value="else">else</option>
                        </select>
                        <br><br>
                    </div>
                    <div>
                    </div>
                </div>
                    <div class="col-md-6">
                        <div class="form-group">
                            <h3 style="text-align: center"><span class="label label-warning">Body</span></h3>
                            <textarea  class="form-control" id="editor1" name="text" placeholder="Body of your article:" required></textarea>
                            <script>CKEDITOR.replace( \'editor1\' );</script>
                        </div>
                    </div>

                            <button type="submit" class="btn btn-default submit"><i class="fa fa-paper-plane" aria-hidden="true"></i>  Save Article</button>



            </form>
        </div>
</section>
</form>
<div class="container">
    <div class="row">

        <div class="col-md-12">
            <h4>Edit Table</h4>
            <div class="table-responsive">
                <table id="mytable" class="table table-bordred table-striped">

                    <thead>
                    <th>Title</th>
                    <th>Topic</th>
                    <th>Edit</th>
                    <th>Delete</th>
                    <th>Visible</th>
                    </thead>
                    <tbody>
    ';
    foreach ($contents as $value){
        echo '
    <tr id="tr_'.$value['id'].'">
        <td>'.$value['title'].'</td>
        <td>'.$value['topic'].'</td>
        <td><a href="'.base_url().'/admin/update/'.$value['id'].'" class="btn btn-default"><span class="glyphicon glyphicon-pencil"></span></a></td>      
        <td class="butt" id="'.$value['id'].'"><a class="btn btn-default"><span class="glyphicon glyphicon-trash"></span></button></td>  
        ';
        if($value['showing']==1) {
            echo '
            <td ><input class="ChangePublish" type = "checkbox" id = "'.$value['id'].'" data-num="'.$value['showing'].'" checked></td>
            </tr>  
        ';}
        if($value['showing']==0) {
            echo '
            <td><input class="ChangePublish" type="checkbox" id = "'.$value['id'].'" data-num="'.$value['showing'].'"></td>
            </tr>  
        ';}

    }
    ;}
?>
</table>
            </div>
        </div>
    </div>
</div>
</body>
</html>