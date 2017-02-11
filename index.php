<?php
$host="localhost";
$username="<username>";
$password="<password>";
$database="********";
$conn = mysqli_connect($host, $username, $password, $database);

if(isset($_GET["request"]))
{
	if($_GET["request"]=="get")
	{
		$sql="SELECT * FROM positio";
		$result=mysqli_query($conn, $sql) or die(mysqli_error($conn));
		$data=mysqli_fetch_array($result);
		$newData=array("ultra1"=>$data["ultra1"], "ultra2"=>$data["ultra2"]);
		if(isset($_GET["os"])){
			if($_GET["os"]=="ios")
			{
				echo json_encode($newData);
			}
		}
		else
			echo json_encode(array("result"=>$newData));
	}
	else if($_GET["request"]=="set")
	{
		$success = 0;
		if(isset($_GET["ultra1"]))
		{
			$ultra1=$_GET["ultra1"];
			$sql="UPDATE positio SET ultra1=$ultra1";
			if(mysqli_query($conn, $sql))
				$success=1;
		}

		if(isset($_GET["ultra2"]))
		{
			$ultra2=$_GET["ultra2"];
			$sql="UPDATE positio SET ultra2=$ultra2";
			if(mysqli_query($conn, $sql))
				$success=1;
		}
		echo $success;
	}
}