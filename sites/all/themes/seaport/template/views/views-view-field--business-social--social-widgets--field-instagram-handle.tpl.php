<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
if (isset($row->field_field_instagram_handle[0]['raw']['value'])){
	$handle = $row->field_field_instagram_handle[0]['raw']['value'];
} else {
	$handle = "seaport_village" ;
}
?>
<div class="instagram-widget">
	<div class="block-title">
		<h2><span>Instagram @<?=$handle?></span></h2>
	</div>
	<iframe allowtransparency="true" frameborder="0" scrolling="no" src="http://widget.websta.me/in/<?=$handle?>/?s=89&w=3&h=4&b=0&p=2" style="border:none;overflow:hidden;width:273px; height: 364px"></iframe><!-- websta - web.stagram.com -->
</div>

<?//php print $output; ?>