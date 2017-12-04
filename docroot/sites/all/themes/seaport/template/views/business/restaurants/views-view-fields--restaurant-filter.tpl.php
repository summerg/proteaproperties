<li>
	<a class="btn btn-outline" href="#" data-filter=".<?php print preg_replace('/[^a-z]/', '', str_replace("&amp;", "", strtolower(strip_tags($fields['name']->content))));?>" onClick="ga('send', 'event', 'filter', 'restaurants', '<?php print strip_tags($fields['name']->content); ?>');">
		<?php print $fields['name']->content; ?>
	</a>
</li>


