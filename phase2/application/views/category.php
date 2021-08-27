<?php
include 'templates/catheader.php';
?>
<body>
<?php $_SESSION['likes']='0';?>
<ul>
    <nav>
        <div class="container-fluid">
            <div class="navbar-header">
            </div>
            <li><a href="http://localhost/category/1">Home</a></li>
            <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Contact<span class="caret"></span></a>
                <ul class="dropdown-menu">
                    <li><a href="http://localhost/register/insert_user">Registration</a></li>
                    <li><a href="http://localhost/register/login">Signing in</a></li>
                </ul>
            </li>
            <li><a href="http://localhost/map">Map</a></li>
            <li><a href="http://localhost/video">video</a></li>
            <li style="float: right"><a href="http://localhost/about">about</a></li>
        </div>
    </nav>
</ul>
<div class="col-sm-2">
    <nav class="nav-sidebar">
        <ul class="nav"  style="background-color: #37D980">
            <li class="active"  style="background-color: whitesmoke"><a href="http://localhost/category/1"><span class="glyphicon glyphicon-star"></span> Topic</a></li>
            <li><a href="http://localhost/category/topic/athletic/1">Athletic</a></li>
            <li><a href="http://localhost/category/topic/political/1">Political</a></li>
            <li><a href="http://localhost/category/topic/cultural/1">Cultural</a></li>
            <li><a href="http://localhost/category/topic/religious/1">Religious</a></li>
            <li><a href="http://localhost/category/topic/historical/1">Historical</a></li>
            <li><a href="http://localhost/category/topic/scientific/1">Scientific</a></li>
            <li><a href="http://localhost/category/topic/else/1">others</a></li>
        </ul>
    </nav>
</div>
<div class="col-sm-10">

<?php
$_SESSION['ad']='false';
$x=0;
$z=0;
foreach ($contents as $value){
    $z++;
    if ($x<3){
        if ($value['showing']==1){

            $x++;

                echo '
    <div class="panel panel-default" xmlns="http://www.w3.org/1999/html">
        <div class="panel-heading">
            <div class="clearfix"></div>
        </div>
        <div class="panel-body">
            <div class="media" style="text-align: center">
                 <div>
                 <a href="http://localhost/article/' .$value['id'].'">
                    <img src=../../'.$value['image'].' align="left" style="width: 250px; height: 150px">
                </a>
                </div>
                <div class="media-body">
                    <h2 class="media-heading" style="color: #f9f2f4; background-image:url(../../../files/wall6.jpg);margin: 10px" > <p>'.$value['title'].'</p></h2>
                    <div class="clearfix"></div>

                </div>
                <h5 style="text-align: left;">'.$value['pretext'].'</h5>
                    <button type="button" id="'.$value['id'].'" data-num="'.$value['likes'].'"  class="btn btn-info"><span class="glyphicon glyphicon-thumbs-up"></span><br><span class="JaLike">'.$value['likes'].'</span></button>
                       
            </div>
            
        </div> 
    </div>
    
';}}
    if ($value['showing']==0){
        $z--;
    }
}
?>
<?php
$z=$z-1;
$y=1;
echo '
    
            </div>
                <div class="col-md-12" style="text-align: center">
                    <ul class="pagination pagination-sm pull-right">';
                    for ($y=1;$y<=($_SESSION['count']-1)/3+1;$y++){
                    echo'    
                            <li><a href="http://localhost/category/'.$y.'">'.$y.'</a></li>
                        ';}
                        echo '
                    </ul>
            </div>
            ';
?>
<?php
include 'templates/catfooter.php';
?>