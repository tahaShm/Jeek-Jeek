<?php  if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class connect extends CI_Model
{

    public function __construct()
    {
        parent::__construct();
        $this->load->helper(array('form', 'url'));
        $this->load->database();
        $this->load->library('session');
    }

    public function connectToDb()
    {

        $query = $this->db->get('user');
        $query1 = $this->db->get('admin');
        $query2 = $this->db->get('content');
        return $query->result_array();
        return $query1->result_array();
        return $query2->result_array();
    }
    //public function func_join($id)
    //{
    //    $this->db->select('*');
    //    $this->db->from('user u');
    //    $this->db->join('admin a', 'u.name = a.name');
    //    $this->db->where('a.id',$id);
    //    $this->db->order_by('a.id','asc');
    //    $query = $this->db->get();
    //    if($query->num_rows() != 0)
    //    {
    //        return $query->result_array();
    //    }
    //    else
    //    {
    //        return false;
    //    }
    //}


}