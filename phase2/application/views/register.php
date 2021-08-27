<html>
<head>
    <title>user's insert</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <script src="../../ckeditor/ckeditor.js"></script>
    <style>
        *Contact sectiom*/
        .content-header{
            font-family: 'Oleo Script', cursive;
            color:#fcc500;
            font-size: 45px;
        }

        .section-content{
            text-align: center;

        }
        #contact{

            font-family: 'Teko', sans-serif;
            padding-top: 60px;
            width: 100%;
            width: 100vw;
            height: 800px;
            background: #3a6186; /* fallback for old browsers */
            background: -webkit-linear-gradient(to left, #ffff00 ,#f89406); /* Chrome 10-25, Safari 5.1-6 */
            background: linear-gradient(to left, #00ff00 , #0683c9); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */

            color : #fff;
        }
        .contact-section{
            padding-top: 40px;
        }
        .contact-section .col-md-6{
            width: 50%;
        }

        .form-line{
            border-right: 1px solid #B29999;
        }

        .form-group{
            margin-top: 10px;
        }
        label{
            font-size: 1.3em;
            line-height: 1em;
            font-weight: normal;
        }
        .form-control{
            font-size: 1.3em;
            color: #080808;
        }
        textarea.form-control {
            height: 135px;
            /* margin-top: px;*/
        }

        .submit{
            font-size: 1.1em;
            float: right;
            width: 150px;
            background-color: transparent;
            color: #fff;

        }
        table {
            font-family: arial, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }

        td, th {
            border: 1px solid purple;
            text-align: left;
            padding: 8px;
        }

        tr:nth-child(even) {
            background-color: deeppink;
        }
    </style>
</head>
<body>
<?= form_open_multipart('register/insert_user');?>
<link href="https://fonts.googleapis.com/css?family=Oleo+Script:400,700" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Teko:400,700" rel="stylesheet">
<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet">
    <section id="contact">
        <div class="section-content">
            <h1 class="section-header">User Insert</h1>
        </div>
        <div class="contact-section">
            <div class="container">
                <form>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-primary">Name</span></h3>
                        <input type="text" class="form-control" id="name" name="name" placeholder=" Enter Username">
                    </div>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-primary">Family name</span></h3>
                        <input type="text" class="form-control" id="lname" name="lname" placeholder="Enter Family name:">
                    </div>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-primary">password</span></h3>
                        <input type="password" class="form-control" id="password" name="password" placeholder="Password">
                        <br><br>
                    </div>
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-warning">Image</span></h3>
                        <input type="file" class="form-control" id="image" name="image" >
                        <br><br>
                    </div>
                    <button type="submit" class="btn btn-default submit"onclick="alert('If you filled -name- , -family name- and -password- You have successfully registered')"> <i class="fa fa-paper-plane" aria-hidden="true">Save User</i></button>
                </form>
            </div>
    </section>
</body>

</html>